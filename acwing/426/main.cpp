// 题目：开心的金明
// 思路来源：01背包

#include <iostream>

using namespace std;

const int N = 30010;

int f[N];

int main() {
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int v, p; cin >> v >> p;
        for (int j = m; j >= v; j--) f[j] = max(f[j], f[j-v] + v*p);
    }
    cout << f[m] << endl;
    return 0;
}