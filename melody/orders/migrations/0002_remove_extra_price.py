# Generated by Django 2.2.3 on 2019-07-28 05:28

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('orders', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='extra',
            name='price',
        ),
    ]
