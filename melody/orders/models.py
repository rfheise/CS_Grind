from django.db import models
from django.contrib.auth.models import User

class Categories(models.Model):
    name = models.CharField(max_length=1024)

    def __str__(self):
        return f"{self.name}"

class Extra(models.Model):
    name = models.CharField(max_length=1024)
    price = models.FloatField(blank = True, null = True)
    availability = models.BooleanField(default = True)
    many = models.BooleanField(default = False)

    def __str__(self):
        return f"{self.name}"

    @property
    def usd(self):
        return "{0:.2f}".format(self.price)

class Food(models.Model):
    name = models.CharField(max_length=1024)
    price = models.FloatField()
    comboprice = models.FloatField(blank = True,null = True)
    attributes = models.ManyToManyField(Extra, blank = True, related_name ="fbyatt")
    availability = models.BooleanField(default = True)
    category = models.ManyToManyField(Categories, related_name = "foods")
    extrasauce = models.BooleanField(default = False)

    def __str__(self):
        return f"{self.name}"
        
    @property
    def usd(self):
        return "{0:.2f}".format(self.price)

class Orders(models.Model):
    usernameid = models.ForeignKey(User, on_delete = models.PROTECT , related_name = "orders")
    date = models.DateTimeField(auto_now_add = True)
    complete = models.BooleanField(default = False)
    usercomplete = models.BooleanField(default = False)

    def __str__(self):
        user = self.usernameid
        return f"{user.first_name} - {user.last_name}"

    @property
    def total(self):
        total = 0
        if self.items:
            for item in self.items:
                total += item.price
        return "{0:.2f}".format(total)



class Eachitem(models.Model):
    orderid = models.ManyToManyField(Orders, related_name = "items")
    foodid = models.ForeignKey(Food, on_delete = models.PROTECT ,related_name = "fooditem" )
    attributes = models.ManyToManyField(Extra, related_name = "carteditem", blank = True)
    price = models.FloatField(default = 0)


# Create your models here.
