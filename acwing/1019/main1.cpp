// 题目：庆功会
// 思路来源：多重背包问题

// f[i][j] = max(f[i-1][j-k*v]+k*w) for k st 0 <= k <= s and j >= k*v

#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 510, M = 6010;

int f[M];

int main() {
    int n, m; cin >> n >> m;
    REP(i, n) {
        int v, w, s; cin >> v >> w >> s;
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= s && j >= k * v; k++) 
                f[j] = max(f[j], f[j-k*v] + k*w);
    }
    cout << f[m] << endl;
    return 0;
}