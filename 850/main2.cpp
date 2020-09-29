#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
int g[N][N];
int d[N];
bool st[N];

int main() {
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (z < g[x][y])
      g[x][y] = z;
  }

  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  for (int i = 0; i < n; i++) {
    int t = 0;
    for (int j = 1; j <= n; j++) {
      if (st[j]) continue;
      if (!t || d[t] > d[j]) t = j;
    }
    st[t] = true;
    for (int j = 1; j <= n; j++) {
      if (d[t] + g[t][j] < d[j]) d[j] = d[t] + g[t][j];
    }
  }
  if (d[n] >= 0x3f3f3f3f) puts("-1");
  else cout << d[n] << endl;
}
