# Generated by Django 2.2.3 on 2019-07-28 05:35

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('orders', '0003_categories_extrasauce'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='categories',
            name='extrasauce',
        ),
        migrations.AddField(
            model_name='food',
            name='extrasauce',
            field=models.BooleanField(default=True),
        ),
    ]
