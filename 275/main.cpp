// f[k][i1][i2] = max(f[k-1][i1][i2], ....)
// f[k][i1][i2] == 0 if i1 == i2

#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 1; i <= n; i++)

const int N = 110;

int a[N][N];
int f[N<<1][N][N];

int main() {
    int n, m;
    cin >> n >> m;
    REP(i, n) REP(j, m) cin >> a[i][j];
    for (int k = 2; k <= n+m; k++) 
        REP(i1, n) REP(i2, m) { 
            int j1 = k - i1, j2 = k - i2;
            if (i1 > n || i2 > n || j1 > m || j2 > m) continue;           
            if (i1 == i2) f[k][i1][i2] = -0x3f3f3f3f;
            else f[k][i1][i2] = max(f[k-1][i1][i2], max(f[k-1][i1-1][i2], max(f[k-1][i1][i2-1], f[k-1][i1][i2]))) + a[i1][j1] + a[i2][j2];
        }
    cout << f[n+m][n][m] << endl;
    return 0;
}