// 题目：最短编辑距离
// 思路来源：最短路径
// f[i][j] = f[i-1][j-1] if a[i] == a[j] else max(f[i-1][j-1]+1, f[i][j-1]+1, f[i-1][j]+1);
// invalid value: f[i][j] = 0x3f3f3f3f, 本题中不会访问到invalid value
// initial value: f[i][0] = 0, f[0][i] = 0

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 1; i <= n; i++)

const int N = 1010;

char a[N], b[N];
int f[N][N];

int main() {
    int n, m;
    cin >> n >> a+1 >> m >> b+1;
    for (int i = 0; i <= n; i++) f[i][0] = i;
    for (int i = 0; i <= m; i++) f[0][i] = i;
    REP(i, n) REP(j, m) {
        if (a[i] == b[j]) f[i][j] = f[i-1][j-1];
        else f[i][j] = min(f[i][j-1]+1, min(f[i-1][j]+1, f[i-1][j-1]+1));
    }
    cout << f[n][m] << endl;
}