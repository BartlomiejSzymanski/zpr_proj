#include "Game.h"
#include <iostream>

void Game::turn()
{
    // to do 
}

win Game::is_won()
{
    win result;
    result.sign_ = sign::nic;
    result.win = false;
    int x = this->X.get()->getSize();


    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < this->X.get()->getGrid()[i].size(); ++j) {
            try {
                if (std::get<sign>(this->Y.GetField(i, j)) != sign::nic) {

                    if (j + 2 < x && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i, j + 1)) && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i, j + 2))) {
                        result.win = true;
                        result.sign_ = std::get<sign>(this->Y.GetField(i, j));
                        return result;  // Sprawdzenie poziomej linii
                    }

                    if (i + 2 < x && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i + 1, j)) && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i + 2, j))) {
                        result.win = true;
                        result.sign_ = std::get<sign>(this->Y.GetField(i, j));
                        return result;  // Sprawdzenie pionowej linii
                    }

                    if (i + 2 < x && j + 2 < x && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i + 1, j + 1)) && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i + 2, j + 2))) {
                        result.win = true;
                        result.sign_ = std::get<sign>(this->Y.GetField(i, j));
                        return result;  // Sprawdzenie skoœnej linii w prawo
                    }

                    if (i + 2 < x && j - 2 >= 0 && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i + 1, j - 1)) && std::get<sign>(this->Y.GetField(i, j)) == std::get<sign>(this->Y.GetField(i + 2, j - 2))) {
                        result.win = true;
                        result.sign_ = std::get<sign>(this->Y.GetField(i, j));
                        return result;  // Sprawdzenie skoœnej linii w lewo
                    }
                }
            }
            catch (const std::bad_variant_access& e)
            {
                std::cout << "jakiœ blad z variantami" << std::endl;
            }


        }
        return result;
    }




}

win Game::is_won(const int x_, const int y_)
{
    Field& UpperGrid = this->X.get()->getGrid()[x_][y_];
    if (std::holds_alternative<Board>(UpperGrid)) {
        PBoard sisiak(new Board(std::get<Board>(UpperGrid).getGrid(), std::get<Board>(UpperGrid).getSize()));
        Game game(sisiak);
        return game.is_won();
    }
    else {
        win result;
        result.sign_ = sign::nic;
        result.win = false;
        return result;
    }

}

