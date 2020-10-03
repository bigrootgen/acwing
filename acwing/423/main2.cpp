// 题目： 采药
// 思路来源： 01背包问题

// f[i][j]: 从前i个物品中选择，总用时不超过j的选择集合;
// f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w[i]);

// contribution set: 略

// invalid set存在contribution, 需要加上限制条件
// if (j-v[i] >= 0)

// invalid value: f[i][j] = 0;
// initial value: f[0][0] = 0;

#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

const int T = 1010, M = 110;

int v[M], w[M];
int f[T];

int main() {
    int n, m; cin >> m >> n;
    REP(i, n) cin >> v[i] >> w[i];
    REP(i, n) 
        for (int j = m; j >= 0; j--) 
            if (j >= v[i]) f[j] = max(f[j], f[j-v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}