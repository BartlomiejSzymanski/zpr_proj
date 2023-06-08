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

            PBoard sisiak(new Board(request->boardsize(), Board(request->boardsize(), sign::nothing)));
	        game = Game(sisiak);

	        mode = request->gamemode();

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
            game.getControler().move(request->row(), request->col(), request->subrow(), request->subcol(), request->player() == 1 ? sign::ex : sign::circle);
            bool subwon = false;
            bool gamewon = false;    
            if(game.is_won(request->row(), request->col()).win)
            {   
                subwon = true;
                game.getControler().move(request->row(), request->col(), request->player() == 1 ? sign::ex : sign::circle);
                gamewon = game.is_won().win;
            }


            std::pair<std::pair<int, int> ,std::pair<int, int> > aimove = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
            if(mode == 1)
            {
                if(std::holds_alternative<Board>(game.getGrid()[request->row()][request->col()]))
                {   
                    std::pair<int, int> aimovetemp = Ai.AiMove(request->row(), request->col(), game, request->player() == 0 ? sign::ex : sign::circle);
                    aimove = std::make_pair(std::make_pair(request->row(), request->col()), aimovetemp);
                }
                else
                {
                aimove = Ai.AiMove(game, request->player() == 0 ? sign::ex : sign::circle);
                }
            }
            

            response->set_gamewon(gamewon);
            response->set_subcellwon(subwon);
            response->set_row(aimove.first.first);
            response->set_col(aimove.first.second);
            response->set_subrow(aimove.second.first);
            response->set_subcol(aimove.second.second);
            return grpc::Status::OK;
        }   

    private:
    AiPlayer Ai;
    Game game;
    int mode;

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

	
}




