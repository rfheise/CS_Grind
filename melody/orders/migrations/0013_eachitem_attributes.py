# Generated by Django 2.2.3 on 2019-07-29 23:25

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('orders', '0012_eachitem_orders'),
    ]

    operations = [
        migrations.AddField(
            model_name='eachitem',
            name='attributes',
            field=models.ManyToManyField(related_name='carteditem', to='orders.Extra'),
        ),
    ]
