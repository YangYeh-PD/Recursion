#include <iostream>
#include <vector>
using namespace std;

class board {
    public:
        board(int num1, int num2): row(num1), column(num2) {
            // Setting the board
            int in;
            cout << "Enter the matrix by multiple lines:" << endl;
            // Avoid seg fault
            Board.resize(row);
            for (int i = 0; i < row; ++i) {
                Board[i].resize(column);
                for (int j = 0; j < column; ++j) {
                    cin >> in;
                    Board[i][j] = in;
                }
            }
        };
        ~board() {
            // Printing the board
            cout << "\nnew board" << endl;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    printf("%d ", Board[i][j]);
                }
                printf("\n");
            }
        }

        void setPinNum(int num1, int num2) {
            pin_num = Board[num1][num2];
        }
        int getPinNum(void) {
            return pin_num;
        }

        void numReplace(int num1, int num2, int new_num) {
            Board[num1][num2] = new_num;
            // up
            if (num1 > 0 && Board[num1 - 1][num2] == getPinNum()) {
                numReplace(num1 - 1, num2, new_num);
            }
            // down
            if (num1 < row - 1 && Board[num1 + 1][num2] == getPinNum()) {
                numReplace(num1 + 1, num2, new_num);
            }
            // left
            if (num2 > 0 && Board[num1][num2 - 1] == getPinNum()) {
                numReplace(num1, num2 - 1, new_num);
            }
            // right
            if (num2 < column - 1 && Board[num1][num2 + 1] == getPinNum()) {
                numReplace(num1, num2 + 1, new_num);
            }
        }
    private: 
        int row, column, pin_num;
        vector<vector<int>> Board;
};

int main(int argc, char *argv[]) {
    int row, column;
    cout << "Enter your board size (row x column): ";
    cin >> row;
    cin.ignore(3);
    cin >> column;

    int pin_row, pin_column, number;
    cout << "Enter index, x, y, k (separated by whitespace): ";
    cin >> pin_row;
    cin.ignore();
    cin >> pin_column;
    cin.ignore();
    cin >> number;

    board board1(row, column);
    board1.setPinNum(pin_row, pin_column);
    board1.numReplace(pin_row, pin_column, number);

    return 0;
}