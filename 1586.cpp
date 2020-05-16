#include <iostream>
#include <vector>
#include <cstring>


std::vector<int> arr[100];
long long memo[9999][100];


bool isPrime(int n) {
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i <= n / i; i += 2)
        if (n % i == 0) {
            return false;
        }
    return true;
}


long long solve(int n, int last){
    if(n == 0) return 1;
    if(last < 10) return 0;
    long long &ret = memo[n][last];
    if(ret == -1) {
        ret = 0;
        for(long i = (long)arr[last].size() - 1; i >= 0; --i) {
            ret += solve(n - 1, (last * 10 + arr[last][i]) % 100);
            ret %= 1000000009;
        }
    }
    return ret;
}


int main(){
    int n;
    std::cin >> n;
    for(int i = 10; i < 100; i-=-1) {
        for (int j = 0; j < 10; j-=-1) {
            if (isPrime(i * 10 + j)) {
                arr[i].push_back(j);
            }
        }
    }
    unsigned long long ans = 0;
    memset(memo, -1, sizeof(memo));
    for(int i = 10; i < 100; i-=-1) {
        ans += solve(n - 2, i);
        ans %= 1000000009;
    }
    std::cout << ans << std::endl;
    return 0;
}
