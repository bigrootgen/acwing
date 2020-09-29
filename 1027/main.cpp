// f[k][i1][i2]: 从(1, 1)到(i1, k-i1)和(i2, k-i2)的最大收益
// f[k][i1][i2] = max(f[k-1][i1][i2], f[k-1][i1-1][i2], f[k-1][i1][i2-1], f[k-1][i1-1][i2-1]) + ...
// invalid value: 0
// initial value: 0
// target: f[n<<1][n][n]

#include <iostream>

using namespace std;

const int N = 21;

int a[N][N];
int f[N<<1][N][N];

int main() {
    int n;
    cin >> n;
    int i, j, x;
    while (cin >> i >> j >> x, i|j|x) a[i][j] = x;
    for (int k = 2; k <= n << 1; k++) 
        for (int i1 = 1; i1 <= n; i1++)
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k-i1, j2 = k-i2;
                int t = a[i1][j1];
                if (i1 != i2) t += a[i2][j2];
                f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2]+t);
                f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2-1]+t);
                f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2-1]+t);
                f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2]+t);
            }   
    cout << f[n<<1][n][n] << endl;
    return 0;
}