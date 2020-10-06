// 题目：机器分配
// 思路来源：分组背包问题

// f[i][j]: 从前i组选，分配设备不超过j台的方案
// f[i][j] = max(f[i-1][j], f[i-1][j-k] + a[i][k]);

#include <iostream>

using namespace std;

const int N = 21;

int f[N], a[N], pre[N][N];

void dfs(int x, int y) {
    if (x == 0) return;
    dfs(x-1, y-pre[x][y]);
    cout << x << " " << pre[x][y] << endl;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[j];
        for (int j = m; j >= 1; j--) for (int k = 1; k <= j; k++) if (f[j] < f[j-k] + a[k]) pre[i][j] = k, f[j] = f[j-k] + a[k];
    }
    cout << f[m] << endl;
    dfs(n, m);
}