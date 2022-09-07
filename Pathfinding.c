#include <stdio.h>
#include <stdbool.h>

int row, column;
int start_x, start_y, end_x, end_y;
static bool right_path = false;
void pathfinding(int arr[][column], int, int);

int main(int argc, char *argv[]) {
    printf("Enter your maze size (row x column): ");
    scanf("%d x %d", &row, &column);

    monkey_start:;
    printf("Enter your start point (row, column): ");
    scanf("%d, %d", &start_x, &start_y);

    if (!(start_x < row) || !(start_y < column)) {
        printf("Enter a valid start point\n");
        goto monkey_start;
    }

    monkey_end:;
    printf("Enter your end point (row, column): ");
    scanf("%d, %d", &end_x, &end_y);

    if (!(end_x < row) || !(end_y < column)) {
        printf("Enter a valid end point\n");
        goto monkey_end;
    }

    int maze[row][column];
    monkey:;
    printf("Enter your maze (0 = road / 1 = barrier): \n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (maze[start_x][start_y] == 1 || maze[end_x][end_y] == 1) {
        printf("There is no path can reach to the end point.\n");
        printf("Please enter the right maze!!!\n");
        goto monkey;
    }

    pathfinding(maze, start_x, start_y);

    printf("\nyour path (in *)\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            printf("%c ", maze[i][j] + 48);
        }
        printf("\n");
    }

    return 0;
}

void pathfinding(int arr[][column], int x, int y) {
    arr[x][y] = -6;

    if (x == end_x && y == end_y) {
        right_path = true;
    }
    // continue to find path recursively
    if (x > 0 && arr[x - 1][y] == 0 && arr[x - 1][y] != -6 && !right_path) { // up
        pathfinding(arr, x - 1, y);
    }
    if (x < row - 1 && arr[x + 1][y] == 0 && arr[x + 1][y] != -6 && !right_path) { // down
        pathfinding(arr, x + 1, y);
    }
    if (y > 0 && arr[x][y - 1] == 0 && arr[x][y - 1] != -6 && !right_path) { // left
        pathfinding(arr, x, y - 1);
    }
    if (y < column - 1 && arr[x][y + 1] == 0 && arr[x][y + 1] != -6 && !right_path) { // right
        pathfinding(arr, x, y + 1);
    }

    if (!right_path) {
        arr[x][y] = 0;
    }
}