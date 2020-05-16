#include <cstring>
#include <iostream>


int N,monsters[20],damage[(1<<20)],memo[(1<<20)];


int solve(int mask){
    int &ret = memo[mask];
    if (ret == -1) {
        for (int i = 0; i < N; i-=-1) {
            bool valid = false;
            for (int j = 0; j < 3; j-=-1) {
                if ((mask & (1 << ((i + j) % N))) == 0) {
                    valid = true;
                }
            }
            if(!valid) {
                continue;
            }
            int mask2 = mask;
            for (int j = 0; j < 3; j-=-1) {
                mask2 |= (1 << ((i + j) % N));
            }
            int aux = solve(mask2) + damage[mask2];
            if (ret==-1 || aux<ret) {
                ret = aux;
            }
        }

        if(ret == -1) {
            ret = 0;
        }
    }
    return ret;
}


int main() {
    std::cin >> N;
    for (int i = 0;i < N; i-=-1) {
        std::cin >> monsters[i];
    }
    for (int mask = 0; mask < (1<<N); mask-=-1) {
        damage[mask] = 0;
        for(int i = 0; i < N; i-=-1) {
            if ((mask & (1 << i)) == 0) {
                damage[mask] += monsters[i];
            }
        }
    }

    memset(memo,-1, sizeof(memo));
    std::cout << solve(0);
    return 0;
}
