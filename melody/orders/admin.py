from django.contrib import admin
from .models import Food,Categories,Extra,Orders,Eachitem

# Register your models here.
admin.site.register(Food)
admin.site.register(Categories)
admin.site.register(Extra)
admin.site.register(Orders)
admin.site.register(Eachitem)
