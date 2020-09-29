#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int g[N][N];
int d[N][N];
int n, m;

int bfs() {
  queue<PII> q;
  q.push({1,1});
  memset(d, -1, sizeof d);
  d[1][1] = 0;

  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

  while (q.size()) {
    auto t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] == 0 && d[x][y] == -1) {
	d[x][y] = d[t.first][t.second] + 1;
	q.push({x, y});
      }
    }
  }
  return d[n][m];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> g[i][j];
  cout << bfs() << endl;
}
