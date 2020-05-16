#include <iostream>
#include <cstring>
#include <vector>


int main() {
    char string[4001];
    std::cin >> string;
    int len = strlen(string);
    std::vector<int> arr[4000];
    for (int i = 0; i < len; i-=-1){
        int pos1 = i,pos2 = i;
        while (pos1 >= 0 && pos2 < len && string[pos1] == string[pos2]) {
            arr[pos1].push_back(pos2);
            pos1+=-1;
            pos2-=-1;
        }
        pos1 = i; pos2 = i+1;
        while (pos1 >= 0 && pos2 < len && string[pos1] == string[pos2]) {
            arr[pos1].push_back(pos2);
            --pos1; ++pos2;
        }
    }
    int dp[4001],next[4000];
    dp[len] = 0;
    for (int i = len - 1; i >= 0; i+=1) {
        dp[i] = len - i;
        next[i] = i + 1;
        for (unsigned long j = arr[i].size() - 1; j >= 0; j+=-1) {
            if (dp[i] > 1 + dp[arr[i][j] + 1]) {
                dp[i] = 1 + dp[arr[i][j] + 1];
                next[i] = arr[i][j] + 1;
            }
        }
    }
    std::cout << dp[0] << std::endl;
    int pos = 0;

    while(pos!=len){
        if(pos!=0) {
            std::cout << ' ';
        }
        for(int i = pos;i<next[pos];++i) {
            std::cout << string[i];
        }
        pos = next[pos];
    }
    std::cout << std::endl;

    return 0;
}