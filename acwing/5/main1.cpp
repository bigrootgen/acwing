#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REP_(i, n) for (int i = 1; i <= n; i++)

using namespace std;

const int N =  1010, M = 12010;

int v[N], w[N];
int f[M];

int main() {
    int n, m; cin >> n >> m;
    int cnt = 0;
    REP(i, n) {
        int a, b, s; cin >> a >> b >> s;
        int k = 1; 
        while (k <= s) {
            v[cnt] = k * a;
            w[cnt] = k * b;
            cnt++;
            s -= k;
            k <<= 1;
        }
        if (s) {
            v[cnt] = s * a;
            w[cnt] = s * b;
            cnt++;
        }
    }
    n = cnt;
    REP(i, n) for (int j = m; j >= v[i]; j--) f[j] = max(f[j], f[j-v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}