// f[i][j] = max(f[i-1][j], f[i-1][j-k*v[i]] + k*w[i] for k st j >= k*v[i]);
// f[i][j-v[i]] = max(f[i-1][j], f[i-1][j-v[i]-k*v[i]] + k*w[i] for k st j-v[i] >= k*v[i]) == second part of the above set
// => f[i][j] = max(f[i-1][j], f[i][j-v[i]]);

// f[j] = max(f[j], f[j-v[i]] + w[i] if j >= v[i]);

#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define REP_(i, n) for (int i = 1; i <= n; i++)

const int N = 1010, M = 1010;

int f[M];

int main() {
    int n, m; cin >> n >> m;
    int v, w;
    REP_(i, n) {
        cin >> v >> w;
        for (int j = v; j <= m; j++) 
            f[j] = max(f[j], f[j-v] + w);
    }  
    cout << f[m] << endl;
    return 0;  
}
