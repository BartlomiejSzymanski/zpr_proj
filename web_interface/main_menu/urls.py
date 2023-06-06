from django.urls import path 
from . import views

urlpatterns = {
    path('', views.game, name='game'),
    path('pass_move', views.pass_move, name='pass_move')
    
}
