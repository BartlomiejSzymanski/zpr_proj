from django.shortcuts import redirect, render
from django.http import HttpResponse
import json
# import main_menu.game_pb2 as game_pb2
# import main_menu.game_pb2_grpc as game_pb2_grpc
import grpc 


# To DO:
# 1. Zmienić endpoint z game_options na game
# 2.W if request == POST -> if game mode in -
# 3. Zaimplementować zmianę tury i zapis ruchu
  

def game(request):
    if request.method == 'POST':
        mode = request.POST['game_mode']
        board_size = request.POST['board_size']
        
        # with grpc.insecure_channel('localhost:50051') as channel:
        #     stub = game_pb2_grpc.GameStub(channel)
        #     Move = game_pb2.Move(row=0, col=0, subRow=0, subCol=0,sign='x')
        #     engine_reply = stub.MakeMove(Move)
        #     print(engine_reply)

        return render(request, 'board.html', {'board_size': board_size})
    else:
        return render(request, 'game_options.html')


