// 题目：分组背包问题
// 思路来源：01背包问题

// f[i][j]: 从前i组物品中选，总体积小于j的方案
// f[i][j] = max(f[i-1][j], f[i-1][j-v[i][k]] + w[i][k] for 0 <= k < s[i]);


#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++) // 正向枚举
#define REP_(i, n) for (int i = 1; i <= n; i++)
#define RREP(i, n) for (int i = n; i >= 0; i--) // 反向枚举
#define RREP_(i, n) for (int i = n; i > 0; i--)

using namespace std;

const int N = 110, M = 110;

int v[N][N], w[N][N], s[N];
int f[N];

int main() {
    int n, m; cin >> n >> m;
    REP(i, n) {
        cin >> s[i];
        REP(j, s[i]) cin >> v[i][j] >> w[i][j];
    }   
    REP(i, n) RREP(j, m) REP(k, s[i]) if (j >= v[i][k]) f[j] = max(f[j], f[j-v[i][k]] + w[i][k]);
    cout << f[m] << endl;
    return 0;
}