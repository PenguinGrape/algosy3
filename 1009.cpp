#include <iostream>

int main() {
    long n, k;
    std::cin >> n >> k;
    long arr[19];
    arr[0] = 1;
    arr[1] = k - 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]) * (k - 1);
    }
    std::cout << arr[n];
    return 0;
}