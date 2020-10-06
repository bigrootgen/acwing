// 题目：混合背包问题z
// 思路来源：01背包问题，完全背包问题，多重背包问题

#include <iostream>

using namespace std;

const int N = 1010, M = 1010;

int f[N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v, w, s; cin >> v >> w >> s;
        if (s == -1) for (int j = m; j >= v; j--) f[j] = max(f[j], f[j-v] + w);
        else if (s == 0) for (int j = v; j <= m; j++) f[j] = max(f[j], f[j-v] + w);
        else for (int j = m; j >= 0; j--) for (int k = 0; k <= s && j >= k * v; k++) f[j] = max(f[j], f[j-k*v] + k*w);
    }
    cout << f[m] << endl;
    return 0;
}