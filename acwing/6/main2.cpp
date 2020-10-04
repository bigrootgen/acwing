// f[i][j] = max(f[i-1][j-k*v[i]]+k*w[i] for k st 0 <= k < s[i] and j >= k*v[i])
// q[j]: 当前第j组的最大值
// for 0 <= j <= v[i] - 1:
//      for (int k = j; 
//          

#include <iostream>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 1010, M = 20010;

int q[N], f[N], g[N];

int main() {
    int n, m; cin >> n >> m;
    REP(i, n) {
        int a, b, s; cin >> a >> b >> s;
        memcpy(g, f, sizeof f);
        REP(j, a) {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k+=a) {
                if (tt >= hh && k - q[hh] + 1 > s*a) hh++;
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / a * b <= g[k] - (k-j) / a * b) tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k-q[hh]) / a * b;
            }
        }
        cout << f[m] << endl;
        return 0;
    }
}


