from django.shortcuts import render
from django.http import HttpResponse

def index(request):
    return HttpResponse("Hello world")


def game_options(request):
    if request.method == 'POST':
        if 'singleplayer' in request.POST:
            pass
        elif 'playervscpu' in request.POST:
            pass
    else:
        return render(request, 'game_options.html')

