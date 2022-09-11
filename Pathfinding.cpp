#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class maze {
    public:
        maze(int num1, int num2): row(num1), column(num2) {
            // Avoid seg fault
            Maze.resize(row);
            for (int i = 0; i < row; ++i) {
                Maze[i].resize(column);
            }
            monkey_start:;
                try {
                    cout << "Enter your start point (row, column): ";
                    cin >> start_row;
                    cin.ignore(2);
                    cin >> start_column;
                    if (!(start_row < row) || !(start_column < column)) {
                        throw invalid_argument("Enter a valid start point\n");
                    }
                } catch (invalid_argument &monkey) {
                    cout << monkey.what();
                    goto monkey_start;
                }
                
            monkey_end:;
                try{
                    cout << "Enter your end point (row, column): ";
                    cin >> end_row;
                    cin.ignore(2);
                    cin >> end_column;
                    if (!(end_row < row) || !(end_column < column)) {
                        throw invalid_argument("Enter a valid end point\n");
                    }
                } catch (invalid_argument &monkey) {
                    cout << monkey.what();
                    goto monkey_end;
                }
            
            monkey:;
                try {
                    cout << "Enter your maze (0 = road / 1 = barrier): " << endl;
                    for (int i = 0; i < row; ++i) {
                        for (int j = 0; j < column; ++j) {
                            cin >> Maze[i][j];
                        }
                    }
                    if (Maze[start_row][start_column] == '1' || Maze[end_row][end_column] == '1') {
                        throw invalid_argument("There is no path can reach to the end point\n");
                    }
                } catch(invalid_argument &monkey) {
                    cout << monkey.what();
                    cout << "Please enter the right maze!!!" << endl;
                    goto monkey;
                }
        }
        ~maze() {
            cout << "\nyour path (in *)" << endl;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    cout << Maze[i][j] << " ";
                }
                cout << "\n";
            }
        }

        int getStartx(void) {
            return start_row;
        }
        int getStarty(void) {
            return start_column;
        }

        void pathfinding(int x, int y) {
            Maze[x][y] = '*';
            if (x == end_row && y == end_column) {
                right_path = true;
            }
            // Up
            if (x > 0 && Maze[x - 1][y] != '1' && Maze[x - 1][y] != '*' && !right_path) {
                pathfinding(x - 1, y);
            }
            // Down
            if (x < row - 1 && Maze[x + 1][y] != '1' && Maze[x + 1][y] != '*' && !right_path) {
                pathfinding(x + 1, y);
            }
            // Left
            if (y > 0 && Maze[x][y - 1] != '1' && Maze[x][y - 1] != '*' && !right_path) {
                pathfinding(x, y - 1);
            }
            // Right
            if (y < column - 1 && Maze[x][y + 1] != '1' && Maze[x][y + 1] != '*' && !right_path) {
                pathfinding(x, y + 1);
            }
            if (!right_path) {
                Maze[x][y] = '0';
            }
        }
    private:
        int row, column;
        int start_row, start_column;
        int end_row, end_column;
        static bool right_path;
        vector<vector <char>> Maze;
};

bool maze::right_path = false;

int main(int argc, char *argv[]) {
    int row, column;
    cout << "Enter your maze size (row x column): ";
    cin >> row;
    cin.ignore(3);
    cin >> column;
    maze maze1(row, column);
    maze1.pathfinding(maze1.getStartx(), maze1.getStarty());

    return 0;
}