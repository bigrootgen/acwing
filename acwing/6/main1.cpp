// 题目：多重背包问题III

#include <iostream>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 20010;

int f[N], g[N], q[N];

int main() {
    int n, m; cin >> n >> m;
    REP(i, n) {
        int v, w, s; cin >> v >> w >> s;
        memcpy(g, f, sizeof f);
        REP(j, v) {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k+=v) {
                if (hh <= tt && q[hh] < k - s * v) hh++;
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k-j) / v * w) tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k-q[hh]) / v * w;
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}