// f[i][j][k]: 在前i个物品中选，且氧气不低于j，氮气不低于k，所得到的方案
// f[i][j][k] = min(f[i-1][j][k], f[i-1][j-a[i]][k-b[i]] + w[i]);

#include <iostream>
#include <cstring>

using namespace std;

const int N = 22, M = 80;

int f[N][M];

int main() {
    int n, m, K; cin >> n >> m >> K;
    memset(f, 0x3f, sizeof f);      
    f[0][0] = 0;
    while (K--) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        for (int j = n; j >= 0; j--) for (int k = m; k >= 0; k--) f[j][k] = min(f[j][k], f[max(0,j-v1)][max(0,k-v2)] + w);
    }
    cout << f[n][m] << endl;
    return 0;
}