# Generated by Django 2.2.3 on 2019-07-28 05:43

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('orders', '0004_auto_20190728_0035'),
    ]

    operations = [
        migrations.AddField(
            model_name='extra',
            name='price',
            field=models.FloatField(blank=True, null=True),
        ),
    ]
