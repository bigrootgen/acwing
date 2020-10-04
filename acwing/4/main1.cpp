// f[i][j] = max(f[i-1][j], f[i-1][j-k*v[i]] + k*w[i] for k st j >= k*v[i] and k <= s)

#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REP_(i, n) for (int i = 1; i <= n; i++)

using namespace std;

const int N = 110, M = 110;

int f[N][M];
int v[N], w[N];

int main() {
    int n, m;
    cin >> n >> m;
    int v, w, s;
    REP_(i, n) {
        cin >> v >> w >> s;
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k * v <= j && k <= s; k++) 
                f[i][j] = max(f[i][j], f[i-1][j-k*v] + k*w);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

