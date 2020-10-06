// 题目：机器分配
// 思路来源：背包问题

#include <iostream>

using namespace std;

const int N = 21;

int f[N], pre[N], a[N][N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
        for (int j = m; j >= 0; j--) for (int k = 1; k <= j; k++) {
            if (f[j] < f[j-k] + a[i][k]) pre[i] = k;
            f[j] = max(f[j], f[j-k] + a[i][k]);
        }
    }
    cout << f[m] << endl;
    for (int i = 0; i < n; i++) cout << i+1 << " " << pre[i] << endl;
    return 0;
}