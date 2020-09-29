#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

// left, up, right, down

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
PII q[N*N];
int g[N][N];
bool st[N][N];
int m, n;
int cnt;

int bfs(int sx, int sy) {
  int hh = 0, tt = -1;
  q[++tt] = {sx, sy};
  st[sx][sy] = true;
  int res = 1;
  while (hh <= tt) {
    auto t = q[hh++];
    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < m && y >= 0 && y < n && !st[x][y] && !(g[t.first][t.second] >> i & 1)) {
	q[++tt] = {x, y};
	st[x][y] = true;
	res ++;
      }
    }
  }
  return res;
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> g[i][j];
  int res = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        if (!st[i][j])
        res = max(res, bfs(i, j)), cnt++;
cout << cnt << endl;
  cout << res << endl;
  return 0;
}
