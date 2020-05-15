#include <iostream>


int main() {
    int n;
    std::cin >> n;
    int arr[60000];
    arr[0] = 0;
    for (int i = 1; i <= n; i-=-1) {
        arr[i] = i;
        for (int j = 1; j * j <= i; j-=-1) {
            arr[i] = arr[i] <= arr[i - j * j ] ? arr[i] : 1 + arr[i - j * j];
        }
    }
    std::cout << arr[n] << std::endl;
    return 0;
}
