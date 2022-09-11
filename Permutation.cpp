#include <iostream>
using namespace std;

class permutation {
    public:
        permutation(int num = 1): layers(num) {
            layer = 0;
            ptr = new char[layers];
        }
        ~permutation() {
            delete [] ptr;
        }

        void permute(void) {
            ++layer;
            for (int i = 0; i < layers; ++i) {
                ptr[layer - 1] = i + 65;
                if (layer < layers) {
                    permute();
                } else if (layer == layers) {
                    for (int j = 0; j < layers; ++j) {
                        for (int k = j + 1; k < layers; ++k) {
                            if (ptr[j] == ptr[k]) {
                                goto end;
                            }
                        }
                    }
                    for (int j = 0; j < layers; ++j) {
                        cout << ptr[j] << " ";
                    }
                    cout << endl;
                }
                end:;
            }
            --layer;
            return;
        }
    private:
        int layer, layers;
        char *ptr;
};

int main(int argc, char *argv[]) {
    int user_layers;
    cin >> user_layers;
    permutation permutating(user_layers);
    permutating.permute();

    return 0;
}