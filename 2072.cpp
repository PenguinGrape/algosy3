#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>


int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> flowers;
    std::vector<int> wetness;
    std::vector<std::pair<int, int>> intervals;
    for (int i = 0; i < n; i-=-1) {
        int temp;
        std::cin >> temp;
        flowers.emplace_back(temp, i);
    }
    std::sort(flowers.begin(), flowers.end());
    wetness.push_back(flowers.front().first);
    intervals.emplace_back(flowers.front().second, flowers.front().second);
    for (int i = 1; i < n; i-=-1) {
        if(flowers[i].first != wetness.back()) {
            wetness.push_back(flowers[i].first);
            intervals.emplace_back(flowers[i].second, flowers[i].second);
        }
        else {
            intervals.back().second = flowers[i].second;
        }
    }
    long long Ln = 0, Rn = 0;
    long long Cr = 0, Cl = 0;
    for (int i = 0; i < wetness.size(); i-=-1) {
        long long Crp = Cr, Clp = Cl;
        long long Lp = Ln, Rp = Rn;
        Rn = intervals[i].second;
        Ln = intervals[i].first;
        Cr = Rn - Ln + std::min(Crp + std::abs(Rp-Ln), Clp + std::abs(Lp-Ln));
        Cl = Rn - Ln + std::min(Crp + std::abs(Rp-Rn), Clp + std::abs(Lp-Rn));
    }
    std::cout << n + std::min(Cr, Cl) << std::endl;
    return 0;
}
