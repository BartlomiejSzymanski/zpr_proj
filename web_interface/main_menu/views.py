from django.shortcuts import render
from django.http import HttpResponse

def index(request):
    return HttpResponse("Hello world")



def game_options(request):
    if request.method == 'POST':
        if 'singleplayer' in request.POST:
            return render(request, 'board_size.html')
        elif 'playervscpu' in request.POST:
            pass 
    else:
        return render(request, 'game_options.html')

def start_game(request):
    if request.method == 'POST':
        print(request.POST)