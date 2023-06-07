#include "Game.h"
#include <iostream>
#include <cmath>



win Game::is_won()
{
    win result;
    result.sign_ = sign::nothing;
    result.win = false;
    int grid_size = getBoard()->getSize();
    int sequence_length = grid_size;

    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            try {
                if (std::holds_alternative<sign>(this->controler.GetField(i, j)) && std::get<sign>(this->controler.GetField(i, j)) != sign::nothing) {

                    sign current_sign = std::get<sign>(this->controler.GetField(i, j));

                    // Horizontal line check
                    if (j + sequence_length <= grid_size) {
                        bool is_winning = true;
                        for (int k = 1; k < sequence_length; ++k) {
                            if (!std::holds_alternative<sign>(this->controler.GetField(i, j + k)) || std::get<sign>(this->controler.GetField(i, j + k)) != current_sign) {
                                is_winning = false;
                                break;
                            }
                        }

                        if (is_winning) {
                            result.win = true;
                            result.sign_ = current_sign;
                            return result;
                        }
                    }

                    // Vertical line check
                    if (i + sequence_length <= grid_size) {
                        bool is_winning = true;
                        for (int k = 1; k < sequence_length; ++k) {
                            if (!std::holds_alternative<sign>(this->controler.GetField(i + k, j)) || std::get<sign>(this->controler.GetField(i + k, j)) != current_sign) {
                                is_winning = false;
                                break;
                            }
                        }

                        if (is_winning) {
                            result.win = true;
                            result.sign_ = current_sign;
                            return result;
                        }
                    }

                    // Diagonal line check (right)
                    if (i + sequence_length <= grid_size && j + sequence_length <= grid_size) {
                        bool is_winning = true;
                        for (int k = 1; k < sequence_length; ++k) {
                            if (!std::holds_alternative<sign>(this->controler.GetField(i + k, j + k)) || std::get<sign>(this->controler.GetField(i + k, j + k)) != current_sign) {
                                is_winning = false;
                                break;
                            }
                        }

                        if (is_winning) {
                            result.win = true;
                            result.sign_ = current_sign;
                            return result;
                        }
                    }

                    // Diagonal line check (left)
                    if (i + sequence_length <= grid_size && j - sequence_length + 1 >= 0) {
                        bool is_winning = true;
                        for (int k = 1; k < sequence_length; ++k) {
                            if (!std::holds_alternative<sign>(this->controler.GetField(i + k, j - k)) || std::get<sign>(this->controler.GetField(i + k, j - k)) != current_sign) {
                                is_winning = false;
                                break;
                            }
                        }

                        if (is_winning) {
                            result.win = true;
                            result.sign_ = current_sign;
                            return result;
                        }
                    }
                }
            }
            catch (const std::bad_variant_access& e) {
                std::cout << "jakiœ b³¹d z variantami" << std::endl;
            }
        }
    }

    return result;
}

win Game::is_won(const int x_, const int y_)
{
    Field& UpperGrid = this->board.get()->getGrid()[x_][y_];
    if (std::holds_alternative<Board>(UpperGrid)) {
        PBoard sisiak(new Board(std::get<Board>(UpperGrid).getGrid(), std::get<Board>(UpperGrid).getSize()));
        Game game(sisiak);
        return game.is_won();
    }
    else {
        win result;
        result.sign_ = sign::nothing;
        result.win = false;
        return result;
    }

}

std::pair<int, int> Game::checkWin(const int x_, const int y_, sign player)
{
    Field& UpperGrid = this->board.get()->getGrid()[x_][y_];
    if (std::holds_alternative<Board>(UpperGrid)) {

        PBoard sisiak(new Board(std::get<Board>(UpperGrid).getGrid(), std::get<Board>(UpperGrid).getSize()));
        Game game(sisiak);

        return game.checkWin(player);
    }
    else {
        return std::make_pair(-1, -1);
    }

}

std::pair<int, int> Game::checkWin(sign player) {

    int grid_size = this->board.get()->getSize();

    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if (std::holds_alternative<sign>(this->board.get()->getGrid()[i][j])) {
                if (std::get<sign>(this->board.get()->getGrid()[i][j]) == sign::nothing) {

                    std::shared_ptr<Board> newBoard = std::make_shared<Board>(*this->board);
                    newBoard->getGrid()[i][j] = player;
                    Game game(newBoard);

                    if (game.is_won().sign_ == player && game.is_won().win)
                    {
                        return std::make_pair(i, j);
                    }
                }
            }
        }

    }
    return std::make_pair(-1, -1);
}

int Game::countMovesToWin(const int x_, const int y_, sign player)
{
    Field& UpperGrid = this->board.get()->getGrid()[x_][y_];
    if (std::holds_alternative<Board>(UpperGrid)) {

        PBoard sisiak(new Board(std::get<Board>(UpperGrid).getGrid(), std::get<Board>(UpperGrid).getSize()));
        Game game(sisiak);

        return game.countMovesToWin(player);
    }
    else {
        return -1;
    }

}

int Game::countMovesToWin(sign player) {
    std::shared_ptr<Board>& board = this->board;
    Game game(board);
    if (game.is_won().win && game.is_won().sign_ == player) {
        return 0;
    }

    int minMoves = std::numeric_limits<int>::max();

    for (size_t i = 0; i < board->getGrid().size(); ++i) {
        for (size_t j = 0; j < board->getGrid()[i].size(); ++j) {
            if (std::get<sign>(board->getGrid()[i][j]) == sign::nothing) {

                // Create a copy of the board and make a move
                std::shared_ptr<Board> newBoard = std::make_shared<Board>(*board);
                newBoard->getGrid()[i][j] = player;

                Game game(newBoard);

                // Recursive call to the function for the next player
                int moves = game.countMovesToWin(player);

                // Update the minimum number of moves
                if (moves >= 0 && moves < minMoves) {
                    minMoves = moves;
                }
            }
        }
    }

    // Add the current player's move to the minimum number of moves
    if (minMoves != std::numeric_limits<int>::max()) {
        return minMoves + 1;
    }
    else {
        return -1; // No possible moves
    }
}

int Game::countMovesToWin(sign player, std::unordered_map<std::string, int>& cache) {
    std::shared_ptr<Board>& board = this->board;
    std::string boardState = board->getState(); // Unikalny identyfikator stanu planszy

    // SprawdŸ, czy wynik dla tego stanu planszy jest ju¿ w pamiêci podrêcznej
    if (cache.find(boardState) != cache.end()) {
        return cache[boardState];
    }

    Game game(board);

    // SprawdŸ, czy gracz wygra³ w bie¿¹cym stanie planszy
    if (game.is_won().win && game.is_won().sign_ == player) {
        return 0;
    }

    int minMoves = std::numeric_limits<int>::max();

    for (size_t i = 0; i < board->getGrid().size(); ++i) {
        for (size_t j = 0; j < board->getGrid()[i].size(); ++j) {
            if (std::get<sign>(board->getGrid()[i][j]) == sign::nothing) {

                // Zapisz aktualny stan planszy
                sign originalValue = std::get<sign>(board->getGrid()[i][j]);

                // Wykonaj ruch
                board->getGrid()[i][j] = player;

                // Stwórz now¹ instancjê Game, korzystaj¹c z aktualnej planszy
                Game game(board);

                // Rekurencyjne wywo³anie funkcji dla nastêpnego gracza
                int moves = game.countMovesToWin(player, cache);

                // Przywróæ poprzedni stan planszy
                board->getGrid()[i][j] = originalValue;

                // Zaktualizuj minimaln¹ liczbê ruchów
                if (moves >= 0 && moves < minMoves) {
                    minMoves = moves;
                }
            }
        }
    }

    // Dodaj ruch bie¿¹cego gracza do minimalnej liczby ruchów
    int result;
    if (minMoves != std::numeric_limits<int>::max()) {
        result = minMoves + 1;
    }
    else {
        result = -1; // Brak mo¿liwych ruchów
    }

    // Zapisz wynik dla tego stanu planszy w pamiêci podrêcznej
    cache[boardState] = result;

    return result;
}

size_t Game::getSize()
{
    return this->board.get()->getSize();
}

Grid& Game::getGrid()
{
    return this->board.get()->getGrid();
}

Board* Game::getBoard()
{
    return this->board.get();
}

Controler Game::getControler()
{
    return controler;
}

