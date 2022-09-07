#include <stdio.h>
#include <stdbool.h>

static int target;
static int row, column;

void replace(int[][column], int, int, int);

int main(int argc, char *argv[]) {
    int x, y, k;

    printf("Enter your board size (row x column): ");
    scanf("%d x %d", &row, &column);

    printf("Enter index x, y, k (separated by whitespace): ");
    scanf("%d %d %d", &x, &y, &k);

    printf("Enter the matrix by multiple lines:\n");
    int board[row][column];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            scanf("%d", &board[i][j]);
            getchar();
        }
    }

    target = board[x][y];
    replace(board, x, y, k);

    printf("\nnew board\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void replace(int arr[][column], int x, int y, int k) {
    if (arr[x][y] == target) {
        arr[x][y] = k;
            if (x > 0) { // up
                replace(arr, x - 1, y, k);
            }
            if (x < row - 1) { // down
                replace(arr, x + 1, y, k);
            }
            if (y > 0) { // right
                replace(arr, x, y - 1, k);
            }
            if (y < column - 1) { // left
                replace(arr, x, y + 1, k);
            }
    } else {
        return;
    }
}