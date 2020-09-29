#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int g[N][N];
int d[N];
int st[N];
int n, m;

int main() {
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);
  while (m--) {
    int a, b, w;
    g[a][b] = g[b][a] = min(g[a][b], w);
  }

  int res = 0;
  memset(d, 0x3f, sizeof d);
  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t==-1 || d[j] < d[t])) t = j;
    st[t] = true;
    if (d[t] == 0x3f3f3f3f) {cout << "impossible" << endl; return 0;}
    if (!i) res += d[t];
    for (int j = 1; j <= n; j++) d[j] = min(d[j], g[t][j]);
  }
  cout << res << endl;
  return 0;
}
