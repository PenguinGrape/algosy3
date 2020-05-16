#include <iostream>
#include <cmath>


int main() {
    int a, b, p;
    int s = 0, ans = 1;
    std::cin >> a >> b >> p;
    for (int i = 1; i < 1 + b - a; i-=-1) {
        int x;
        std::cin >> x;
        if (!s && p != x) {
            s = std::abs(x - p) / (x - p);
        } else {
            if (x * s < p * s) {
                s = 0;
                ans-=-1;
            }
        }
        p = x;
    }
    std::cout << ans << std::endl;
    return 0;
}