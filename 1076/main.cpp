#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n;
int g[N][N];
PII q[M];
PII pre[N][N];

void bfs(int sx, int sy) {
  int hh = 0, tt = -1;
  q[++tt] = {sx, sy};
  memset(pre, -1, sizeof pre);
  pre[sx][sy] = {0, 0};

  while (hh <= tt) {
    auto t = q[hh++];
    int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < n && pre[x][y].first == -1 && g[x][y] == 0) {
	q[++tt] = {x, y};
	pre[x][y] = {t.first, t.second};
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> g[i][j];
  bfs (n-1, n-1);
  PII end(0, 0);
  while (true) {
    cout << end.first << " " << end.second << endl;
    if (end.first == n-1 && end.second == n-1) break;
    end = pre[end.first][end.second];
  }
  return 0;
}
