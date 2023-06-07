#include <iostream>
#include <vector>
#include <utility>

#include <myproto/game.pb.h>
#include <myproto/game.grpc.pb.h>

#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>

#include "AiPlayer.h"
#include "Game.h"

class GameService final : public game::Game::Service {
    public:
        virtual ::grpc::Status GameSetup(::grpc::ServerContext* context, const ::game::Setup* request, ::game::EngineResponse* response)
        {
            std::cout << "Server: Create Board of size: \"" << request->boardsize() << "\"." << std::endl;

            response->set_gamewon(0);
            response->set_row(0);
            response->set_col(0);
            response->set_subrow(0);
            response->set_subcol(0);
            return grpc::Status::OK;
        }

        virtual ::grpc::Status MakeMove(::grpc::ServerContext* context, const ::game::Move* request, ::game::EngineResponse* response)
        {
            std::cout << "Server: Player made move : \"" << request->row() << "\n" << request->col() << "\"." << std::endl;

            response->set_gamewon(0);
            response->set_row(0);
            response->set_col(0);
            response->set_subrow(0);
            response->set_subcol(0);
            return grpc::Status::OK;
        }        
};

int main(int argc, char* argv[])
{
    grpc::ServerBuilder builder;
    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());

    GameService my_service;
    builder.RegisterService(&my_service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    server->Wait();
    
    return 0;
}


void setup(Game& game, int& tryb, size_t size, int zadanyTryb) {

	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	game = Game(sisiak);

	tryb = zadanyTryb;
}

// int main()
// {

// 	int tryb;
// 	Game game;
// 	setup(game, tryb, 4, 1);

// 	return 0;
// };


