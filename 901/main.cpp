// dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0}
// f[i, j] = max(f[i - dx[k], j - dy[k]] + 1) for k in range(4) if f[i - dx[k], j - dy[k]] < f[i, j]
// f[i, j] = 1 if for k in range(4), f[i-dx, j-dy] >= f[i, j]

#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;

int n, m;
int g[N][N];
int f[N][N];
bool st[N][N];

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int dp(int x, int y) {
  if (st[x][y]) return f[x][y];
  bool flag = false;
  for (int i = 1; i < 4; i++) {
    if (x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && g[x][y] > g[x+dx[i]][y+dy[i]]) {
      flag = true;
      f[x][y] = max(f[x][y], dp(x+dx[i], y+dy[i]) + 1);
      st[x][y] = true;
    }
  }
  if (!flag) {
    f[x][y] = 1, st[x][y] = true;
  }
  return f[x][y];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> g[i][j];
  memset(f, -1, sizeof f);
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      res = max(res, dp(i, j));
  cout << res << endl;
  return 0;
}
