## @file
# Django views for the game.
# Contains game logic and interaction with gRPC server.

from django.shortcuts import redirect, render
from django.http import HttpResponse, JsonResponse
import game_pb2 as game_pb2
import game_pb2_grpc as game_pb2_grpc
import grpc
import json

def game(request):
    """
    Renders the game view or handles the game form submission.

    :param request: The HTTP request object.
    :type request: django.http.HttpRequest
    :return: The rendered response.
    :rtype: django.http.HttpResponse
    """
    if request.method == 'POST':
        game_mode = request.POST['game_mode']
        board_size = request.POST['board_size']
        setup_game(int(board_size), int(game_mode))
        return render(request, 'board.html', {'board_size': board_size, 'game_mode': game_mode})
    elif request.method == 'GET':
        return render(request, 'game_options.html')

def pass_move(request):
    """
    Handles the gRPC call for passing a player's move to the engine.

    :param request: The HTTP request object.
    :type request: django.http.HttpRequest
    :return: The JSON response.
    :rtype: django.http.JsonResponse
    """
    data = json.loads(request.body)
    row = data["row"]
    col = data["col"]
    subRow = data["subRow"]
    subCol = data["subCol"]
    player = data["currentPlayer"]

    with grpc.insecure_channel('localhost:50051') as channel:
        stub = game_pb2_grpc.GameStub(channel)
        move = game_pb2.Move(row=row, col=col, subRow=subRow, subCol=subCol, player=player)
        engine_reply = stub.MakeMove(move)

    response_data = {
        'gameWon': engine_reply.gameWon,
        'subCellWon': engine_reply.subCellWon,
        'row': engine_reply.row,
        'col': engine_reply.col,
        'subRow': engine_reply.subRow,
        'subCol': engine_reply.subCol
    }
    print(response_data)

    return JsonResponse(response_data)

def setup_game(board_size, game_mode):
    """
    Sets up the game by sending a gRPC request to the engine.

    :param board_size: The size of the game board.
    :type board_size: int
    :param game_mode: The game mode.
    :type game_mode: int
    :return : If setup was successful
    :rtype : bool
    """
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = game_pb2_grpc.GameStub(channel)
        setup = game_pb2.Setup(boardSize=board_size, gameMode=game_mode)
        engine_reply = stub.GameSetup(setup)
        
