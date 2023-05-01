from django.urls import path 
from . import views

urlpatterns = {
    path('game-options/', views.game_options, name='game_options'),
    path("", views.index, name="index")

}