#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define REP_(i, n) for (int i = 1; i <= n; i++)

const int N = 1010, V = 1010;

int f[N];

int main() {
    int n, m; cin >> n >> m;
    int v, w;
    REP_(i, n) {
        cin >> v >> w;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j-v] + w);
    }   
    cout << f[m] << endl;
    return 0;
}