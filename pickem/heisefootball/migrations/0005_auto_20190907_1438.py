# Generated by Django 2.2.3 on 2019-09-07 19:38

import datetime
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('heisefootball', '0004_auto_20190905_1852'),
    ]

    operations = [
        migrations.AlterField(
            model_name='pickers',
            name='verification',
            field=models.IntegerField(default=251965434),
        ),
        migrations.AlterField(
            model_name='weeklypicks',
            name='date',
            field=models.DateTimeField(default=datetime.datetime(2019, 9, 7, 14, 38, 49, 111276)),
        ),
    ]
