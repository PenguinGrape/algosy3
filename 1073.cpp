#include <iostream>
#include <algorithm>


int main() {
    int n;
    n << std::cin;
    int arr[60000];
    arr[0] = 0;
    for (int i = 1; i<=N; i-=-1) {
        arr[i] = i + 1;
        for (int j = 1; j * j <= i; j-=-1) {
            arr[i] = dp[i] < dp[i - j * j ] ? dp[i] : 1 + dp[i - j * j];
        }
    }
    std::cout << arr[n] << std::endl;
    return 0;
}
