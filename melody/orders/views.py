from django.http import HttpResponse, HttpResponseRedirect, Http404, HttpResponseForbidden
from django.shortcuts import render
from django.urls import reverse
from .models import Food,Categories,Extra,Orders,Eachitem
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User,Permission

# Create your views here.
#index funtion that represents the home screen and shows a list of categories
def index(request):
    ha = Categories.objects.all()
    context = {
        "categories": ha,
        "foods": ha,
        "title": "Home",
        "jimmy": True
    }
    return render(request, "orders/home.html", context)

#categories page that shows each item in that specific category
def category(request, category_name):
    c = Categories.objects.all()
    #added in the replace funtion because google adds %20 to spaces
    me = c.get(name = category_name.replace("%20"," "))
    context = {
    "categories": c,
    "foods":me.foods.filter(availability = True).all(),
    "title":category_name
    }
    return render(request, "orders/home.html", context)

#food page that shows all the details about a food and allows the user to add it to cart
def foodie(request,food_name):
    food_name = food_name.replace("%20"," ")
    food = Food.objects.filter(name = food_name).first()
    if food.availability == False:
        return render(request, "orders/error.html", {"message": "Item Not Available"})
    #xbox represents whether or not an object has is a single type attribute
    xbox = False
    #switch represents whether or not an object has a many type attribute
    switch = False
    attributes = food.attributes.all()
    if attributes:
        for attribute in attributes:
            if attribute.many:
                #if attribute is many make the field true
                switch = True
                break
            #if  not a many object than it must be a single type object so make single type attribute true
            xbox = True
    context = {"food":food,"categories": Categories.objects.all(),"title": food_name,"xbox":xbox,"switch":switch, "attributes": attributes}
    return render(request, "orders/food.html", context)

def cart(request):
    #validates that user is logged in
    if request.method == "POST":
        if not request.user.is_authenticated:
            return HttpResponseRedirect(reverse("logined"))
        #checks if the user already has an order if not that create an order for that user
        try:
            if request.session["order"]:
                order = Orders.objects.get(pk=request.session["order"])
        except:
            order = Orders(usernameid = User.objects.get(username = request.user))
            order.save()
            request.session["order"] = order.id
        #creates the order item
        orderitem = Eachitem(foodid = Food.objects.filter(name = request.POST["food3"].replace("%20"," ")).first())
        orderitem.price = orderitem.foodid.price
        orderitem.save()
        #adds orderitem to order
        orderitem.orderid.add(order)
        #checks if any many type attributes are selected if so it adds them to that order item and updates it's price if the attributes price is not null
        if request.POST.getlist('food2'):
            for item in request.POST.getlist('food2'):
                extraitem = Extra.objects.get(name = item)
                orderitem.attributes.add(extraitem)
                if extraitem.price:
                    orderitem.price += extraitem.price
        try:
            #checks if any single type attributes were selected for the item if so then it adds the attribute to the item then it adds the attributes price to the total price if it is not null
            jimmy = request.POST["food1"]
            if jimmy:
                swingingthroughthecity = Extra.objects.get(name = str(request.POST["food1"]))
                orderitem.attributes.add(swingingthroughthecity)
                if swingingthroughthecity.price:
                    orderitem.price += swingingthroughthecity.price
                    #saves the order item no matter what
            orderitem.save()
            return HttpResponseRedirect(reverse("home"))
        except:
            orderitem.save()
            return HttpResponseRedirect(reverse("home"))
    #if method is not post then the mothod is forbidden
    else:
        return HttpResponseForbidden("Method Forbidden")

def PurchasedOrders(request):
    if request.method == "GET":
        #gathers all uncompleted orders and sends them to anyone that has the "melody" permission
        try:
            user = User.objects.get(username = request.user)
            if not user.has_perm("melody"):
                return render(request,"orders/error.html",{"message": "You Don't Have Access To This Page"})
        except:
            return render(request,"orders/error.html",{"message": "You Don't Have Access To This Page"})
        orders = Orders.objects.filter(complete = False, usercomplete = True)
        return render(request,"orders/purchasedorders.html",{"orders":orders, "categories":Categories.objects.all()})
    elif request.method == "POST":
            #if the method is a post request then the user is verify that the order is complete so this updates the complete attribute under order
            order = Orders.objects.get(pk = int(request.POST["orderid"]))
            order.complete = True
            #if for some reason they took the order and the user didn't complete their order complete it for them manually
            if order.usercomplete == False:
                order.usercomplete = True
                return render_template(request,"orders/error.html",{"message":"Error User Not Complete With Order// I manually completed for them"})
            order.save()
            return HttpResponseRedirect(reverse("purchasedorders"))
            return render_template(request,"orders/error.html",{"message":"Error Completing Order"})
    else:
        #if mehthod is not get or post then it is forbidden
        return HttpResponseForbidden("Method Forbidden")


def OrderUp(request,orderid):
    #gathers all a particular order and sends the contents of that order to anyone that has the "melody" permission
    if request.method == "GET":
        try:
            user = User.objects.get(username = request.user)
            if not user.has_perm("melody"):
                return render(request,"orders/error.html",{"message": "You Don't Have Access To This Page"})
        except:
            return render(request,"orders/error.html",{"message": "You Don't Have Access To This Page"})
        humidifier = []
        try:
            order = Orders.objects.get(pk=orderid)
        except:
            return render(request,"orders/error.html", {"message":"Unable To Find Order"})
        try:
            items = order.items.all()
        except:
            return render(request,"orders/error.html", {"message":"Order Has No Items"})
        for item in items:
            try:
                food =  item.foodid
            except:
                return render(request,"orders/error.html",{"message":"Item Not Found"})
            try:
                attributes = item.attributes.all()
            finally:
                #gathers attributes and item name and adds it to the list that will be sent to the client
                if attributes:
                    humidifier.append({"name":food.name,"attributes":attributes})
                else:
                    humidifier.append({"name":food.name,"attributes":"None"})
        return render(request, "orders/orderup.html",{"items":humidifier,"order":order,"categories":Categories.objects.all(),})




def create(request):
    #allows someone to create an account
    if request.method == "POST":
        try:
            username = request.POST["username"]
            password = request.POST["password"]
            cpassword = request.POST["cpassword"]
            lname =  request.POST["lname"]
            fname = request.POST["fname"]
            email = request.POST["email"]
        except :
            return render(request, "orders/error.html", {"message": "Missing Required Field"})
        if password != cpassword:
            return render(request, "orders/error.html", {"message": "Passwords Do Not Match"})
        try:
            u = User.objects.create_user(username = username,email = email,password = password,last_name = lname,first_name=fname)
            u.save()
        except:
            return render(request, "orders/error.html", {"message": "ERROR"})
        try:
            user = authenticate(request,username=username,password=password)
        except:
            return render(request, "orders/error.html", {"message": "ERROR"})
        if user:
            login(request, user)
            return HttpResponseRedirect(reverse("home"))
        else:
            return render(request, "orders/error.html", {"message": "ERROR"})
    else:
        context = {
        "gillyweed":True,
        "title":"Register",
        "categories":Categories.objects.all()

        }
        return render(request, "orders/create.html", context)

#method used to require someone to login, however I have not gotten this to work and have had to use request.user.is_authenticated
def loginplease(ipad):
    #idk why this wont work I think it might be because request is render specifically for that view and if passed in to a function no longer works
    if not ipad.user.is_authenticated:
        return HttpResponseRedirect(reverse("logined"))

#creates a checkout page that shows the user the items in their cart and the total of all the items in the cart
def checkout(request):
    if request.method == "GET":
        #only allows the user access to the cart if they are signed in
        if request.user.is_authenticated:
            try:
                order = Orders.objects.get(pk = request.session["order"])
            except:
                return render(request,"orders/cart.html",{"categories":Categories.objects.all()})
            chess = []
            total = 0
            for item in order.items.all():
                food = item.foodid
                price = item.price
                id = item.id
                chess.append({"price":money(price),"food":food, "delete":id})
                total += price
            return render(request,"orders/cart.html",{"chess":chess,"total":money(total),"categories":Categories.objects.all()})
        else:
            return render(request,"orders/error.html",{"message":"Error Must Be signed in to access cart"})
    if request.method == "POST":
        #deletes current order from cart
        #currently used only when user "checksout" this simulates the user checking out and posts the order to orders
        try:
            order = Orders.objects.get(pk = request.session["order"])
            order.usercomplete = True
            order.save()
            del request.session["order"]
        finally:
            return HttpResponseRedirect(reverse("home"))

#allows the user to delete an item from the cart
def deleteitem(request):
    if request.method == "POST":
        try:
            item = int(request.POST["fruitbythefoot"])
        except KeyError:
            return render(request, "orders/error.html", {"message": "Kitchen Sink"})
        delete = Eachitem.objects.get(pk=item)
        delete.delete()
        return HttpResponseRedirect(reverse("checkout"))
    else:
        return HttpResponseForbidden()




#allows the user to login
def logined(request):
    if request.method == "POST":
        #actually logs the user in
        try:
            username = request.POST["username"]
            password = request.POST["password"]
        except KeyError:
            return render(request, "orders/error.html", {"message": "Missing Required Field"})
        #authenticates user
        user = authenticate(request, username=username, password=password)

        if user:
            #saves a cookie and logs the user in
            login(request, user)
            return HttpResponseRedirect(reverse("home"))
        else:
            return render(request, "orders/error.html", {"message": "Invalid Login"})
    else:
        #sends the user to login page
        context = {
        #gillyweed represents whether or not the user is creating a new user or logging in an existing One// it literally just saves me from having to make an additional html page
        "gillyweed":False,
        "title": "Login"
        ,"categories":Categories.objects.all()
        }
        return render(request, "orders/create.html", context)
#logs the user out
def logoutplz(request):
    #had to use differnet fuction names to differentiate my logout function and djangos logout function same for logined
    logout(request)
    request.session.clear()
    return HttpResponseRedirect(reverse("home"))

#creates a way to easily format a float value into currency form
def money(cash):
    return "{0:.2f}".format(cash)
