#include <stdio.h>
#include <stdbool.h>

void permutation(char*);
bool isSame(char*);

static int number, layers = 0;

int main(int argc, char *argv[]) {
    
    scanf("%d", &number);
    char array[number];

    // Initializing
    for (int i = 0; i < number; i++) {
        array[i] = 97;
    }

    permutation(array);

    return 0;
}

void permutation(char *array) {
    if (layers == number) {
        if(!isSame(array)) {
            for (int i = 0; i < number; i++) {
                printf("%c ", array[i]);
            }
            printf("\n");
        }
        layers--;
        return;
    }
    for (char alpha = 65; alpha < number + 65; alpha++) {
        array[layers] = alpha;
        layers++;
        permutation(array);    
     }
     if (layers) {
        array[layers] = 65;
        layers--;
     }
     return;
}

bool isSame(char *array) {
    for (int i = 0; i < number; i++) {
        for (int j = i + 1; j < number; j++) {
            if (array[i] == array[j] && array[i] != 97) {
                return true;
            }
        }
    }
    return false;
}