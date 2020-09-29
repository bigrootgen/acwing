#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m, k;
int g[N][N];
int d[N][N];

int main() {
  cin >> n >> m >> k;
  memset(g, 0x3f, sizeof g);
  memset(d, 0x3f, sizeof d);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (g[x][y] > z) {
      g[x][y] = z;
      d[x][y] = z;
    }
  }
  
  for (int i = 1; i <= n; i++) d[i][i] = 0;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  while (k--) {
    int x, y;
    cin >> x >> y;
    if (d[x][y] > 0x3f3f3f3f/2) cout << "impossible" << endl;
    else cout << d[x][y] << endl;
  }

  return 0;
}
