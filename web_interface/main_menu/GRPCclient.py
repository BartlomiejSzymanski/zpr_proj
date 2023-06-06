
import game_pb2 as game_pb2
import game_pb2_grpc as game_pb2_grpc
import grpc 



if __name__ == "__main__":
    print("START")
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = game_pb2_grpc.GameStub(channel)
        Move = game_pb2.Move(row=0, col=0, subRow=0, subCol=0,player='x')
        engine_reply = stub.MakeMove(Move)
        print("CLIENT: Request has been made")