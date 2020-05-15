#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

# define LOOP(i,s,e) for (int i=s; i<e; ++i)


using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> hash(1,0);

    for (int i = 1; i < n+1; i++) {
        int pat = i*i;
        if (pat > n) break;
        hash.push_back(pat);
    }

    vector<int> vec(n+1, INT_MAX);
    vec[0] = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i] == INT_MAX) {
            continue;
        }
        for (int j = 1; j < hash.size(); j++) {
            if (i+hash[j] > n) {
                break;
            }
            vec[i+ hash[j]] = min(vec[i+ hash[j]], vec[i] +1);
        }
    }
    cout << vec[n];
    return 0;
}