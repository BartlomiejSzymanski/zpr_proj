import main_menu.game_pb2 as game_pb2
import main_menu.game_pb2_grpc as game_pb2_grpc
import grpc
from concurrent import futures


class DefinedGameServicer(game_pb2_grpc.GameServicer):
    def GameSetup(self, request, context):
        print("Received request",request)
        
        engine_response = game_pb2.EngineResponse()
        engine_response.gameWon = 1234
        return engine_response
    
    def MakeMove(self, request, context):
        print("Received request\n",request)
        
        print(request.row,"\n", request.col, "\n", request.subRow, "\n", request.subCol, "\n", request.player)
        engine_response = game_pb2.EngineResponse()
        engine_response.gameWon = 0
        engine_response.subCellWon = 1
        engine_response.row = 0
        engine_response.col = 0
        engine_response.subRow = 0
        engine_response.subCol = 0
        return engine_response
    


def run():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    game_pb2_grpc.add_GameServicer_to_server(DefinedGameServicer(), server)
    server.add_insecure_port("localhost:50051")
    server.start()
    server.wait_for_termination()
    
if __name__ == "__main__":
    run()