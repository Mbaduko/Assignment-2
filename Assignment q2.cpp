#include <iostream>

const int ROWS = 6;
const int COLS = 7;

enum Player { None, Red, Yellow };


bool checkWin(const Player board[ROWS][COLS], Player currentPlayer) {
    // Check horizontal
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS - 3; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row][col] == board[row][col + 1] &&
                board[row][col] == board[row][col + 2] &&
                board[row][col] == board[row][col + 3]) {
                return true;
            }
        }
    }

    // Check vertical
    for (int row = 0; row < ROWS - 3; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row][col] == board[row + 1][col] &&
                board[row][col] == board[row + 2][col] &&
                board[row][col] == board[row + 3][col]) {
                return true;
            }
        }
    }

    // Check diagonal (ascending)
    for (int row = 3; row < ROWS; ++row) {
        for (int col = 0; col < COLS - 3; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row][col] == board[row - 1][col + 1] &&
                board[row][col] == board[row - 2][col + 2] &&
                board[row][col] == board[row - 3][col + 3]) {
                return true;
            }
        }
    }

    // Check diagonal (descending)
    for (int row = 3; row < ROWS; ++row) {
        for (int col = 3; col < COLS; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row][col] == board[row - 1][col - 1] &&
                board[row][col] == board[row - 2][col - 2] &&
                board[row][col] == board[row - 3][col - 3]) {
                return true;
            }
        }
    }

    return false;
}

void printBoard(const Player board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        std::cout<<"\t";
        for (int col = 0; col < COLS; ++col) {
            char symbol = '_';
            if (board[row][col] == Red) {
                if (checkWin(board, Red)){
                    symbol='*';
                }
                else
                  symbol = 'R';
            } else if (board[row][col] == Yellow) {
                if (checkWin(board, Yellow)){
                    symbol='*';
                }
                else
                  symbol = 'Y';
            }
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
    std::cout<<"\t";
    for (int col = 0; col < COLS; ++col) {
        std::cout << col << ' ';
    }
    std::cout << std::endl;
}

bool isValidMove(const Player board[ROWS][COLS], int col) {
    return col >= 0 && col < COLS && board[0][col] == None;
}

bool makeMove(Player board[ROWS][COLS], int col, Player currentPlayer) {
    if (!isValidMove(board, col))
        return false;

    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == None) {
            board[row][col] = currentPlayer;
            return true;
        }
    }

    return false;
}


int main() {
    Player board[ROWS][COLS] = { {None} };
    Player currentPlayer = Red;
    bool gameOver = false;

    while (!gameOver) {
        //printBoard(board);
        Again:
        std::cout << "Player " << (currentPlayer == Red ? "Red" : "Yellow") << ", enter column (0-6): ";

        int col;
        std::cin >> col;
        if (makeMove(board, col, currentPlayer)) {
            std::cout<<"Now board looks like:\n";
            printBoard(board);
            if (checkWin(board, currentPlayer)) {
                std::cout << "Player " << (currentPlayer == Red ? "Red" : "Yellow") << " wins!" << std::endl;
                //printBoard(board);
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == Red) ? Yellow : Red;
            }
        } else {
            std::cout << "Invalid move. Try again!" << std::endl;
            goto Again; 
        }
        
    }

    return 0;
}
