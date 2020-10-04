from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name = "home"),
    path("menu/<str:category_name>", views.category, name = "category"),
    path("category/<str:food_name>", views.foodie, name = "foodie"),
    path("user/login", views.logined, name = "logined"),
    path("user/create", views.create, name ="newuser"),
    path("user/logout", views.logoutplz, name= "logout"),
    path("checkout/addtocart", views.cart, name = "cart"),
    path("checkout", views.checkout, name = "checkout"),
    path("checkout/deleteitem", views.deleteitem, name = "delete"),
    path("fruitbythefoot/orders", views.PurchasedOrders, name = "purchasedorders"),
    path("fruitbythefoot/orders/<int:orderid>",views.OrderUp, name = "orderup")
]
