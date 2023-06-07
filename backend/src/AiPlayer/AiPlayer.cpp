#include "AiPlayer.h"
#include <random>

std::pair<int, int> AiPlayer::AiMove(int x_, int y_, Game game, sign player)
{
    std::vector<std::vector<int>> weight;
    if (game.checkWin(x_, y_, player).first != -1) {
        return game.checkWin(x_, y_, player);
    }

    for (size_t i = 0; i < game.getSize(); ++i) {
        std::vector<int>  weightRow;
        for (size_t j = 0; j < game.getSize(); ++j) {

            if (std::get<sign>(std::get<Board>(game.getGrid()[x_][y_]).getGrid()[i][j]) == sign::nothing) {

                if (std::holds_alternative<Board>(game.getGrid()[i][j])) {

                    PBoard pboard(new  Board(std::get<Board>(game.getGrid()[i][j])));
                    std::shared_ptr<Board> newBoard = std::make_shared<Board>(*pboard);
                    Game game(newBoard);

                    weightRow.push_back(game.countMovesToWin(player == sign::ex ? sign::circle : sign::ex, this->cache));

                }
                else {
                    weightRow.push_back(game.getSize() - 4);
                }
            }
        }
        weight.push_back(weightRow);
    }



    std::vector<int> help;
    std::vector<int> rows;

    for (size_t k = 0; k < game.getSize(); ++k) {
        auto maxElementIterator = std::max_element(weight[k].begin(), weight[k].end());
        help.push_back(*maxElementIterator);
        std::size_t maxIndex = std::distance(weight[k].begin(), maxElementIterator);
        rows.push_back(maxIndex);
    }
    auto maxElementIterator = std::max_element(help.begin(), help.end());
    int maxValue = *maxElementIterator;


    std::vector<int> maxIndices;


    for (std::size_t i = 0; i < help.size(); ++i) {
        if (help[i] == maxValue) {
            maxIndices.push_back(i);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> dist(0, maxIndices.size() - 1);
    std::size_t randomIndex = maxIndices[dist(gen)];


    return std::make_pair(randomIndex, rows[randomIndex]);
}

std::pair<std::pair<int, int>, std::pair<int, int>> AiPlayer::AiMove(Game game, sign player)
{

    std::pair<int, int> pair = game.checkWin(player);
    if (pair.first != -1) {
        return  std::make_pair(std::make_pair(pair.first, pair.second), AiMove(pair.first, pair.second, game, player));
    }


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> dist(0, game.getSize() - 1);
    while (true) {
        int randomX = dist(gen);
        int randomY = dist(gen);
        if (std::holds_alternative<Board>(game.getGrid()[randomX][randomY])) {
            return std::make_pair(std::make_pair(randomX, randomY), AiMove(randomX, randomY, game, player));
        }
    }

}