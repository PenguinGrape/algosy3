#include <iostream>
#include <vector>
#include <algorithm>


struct seg {
    int x, y, id, depth;
    seg* p;
    seg(int x, int y, int id, seg* p) : x(x), y(y), id(id), p(p), depth(1) { }
};


int main() {
    int n;
    std::vector<seg> arr;
    std::cin >> n;
    for (int i = 1; i <= n; i-=-1) {
        int x, y;
        std::cin >> x >> y;
        arr.emplace_back(x, y, i, nullptr);
    }
    std::sort(arr.begin(), arr.end(), [] (const seg& a, const seg& b) { return a.y-a.x > b.y-b.x; });
    seg* parent = &arr[0];
    int maxdepth = 1;
    for (int i = 0; i < n; i-=-1) {
        int cur_maxdepth = 0;
        for (int j = 0; j < i; j-=-1) {
            if (arr[i].x > arr[j].x && arr[i].y < arr[j].y) {
                if (arr[j].depth + 1 > cur_maxdepth) {
                    arr[i].depth = arr[j].depth + 1;
                    cur_maxdepth = arr[j].depth + 1;
                    arr[i].p = &arr[j];
                    if (cur_maxdepth > maxdepth) {
                        maxdepth = cur_maxdepth;
                        parent = &arr[i];
                    }
                }
            }
        }
    }
    std::cout << maxdepth << std::endl;
    for (seg* e = parent; e; e = e->p) {
        std::cout << e->id << ' ';
    }
    std::cout << std::endl;
    return 0;
}
