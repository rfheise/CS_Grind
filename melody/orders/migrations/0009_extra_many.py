# Generated by Django 2.2.3 on 2019-07-28 06:17

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('orders', '0008_extra_availability'),
    ]

    operations = [
        migrations.AddField(
            model_name='extra',
            name='many',
            field=models.BooleanField(default=False),
        ),
    ]
