#include <iostream>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;

const int N = 1010;

int n, m;
char g[N][N];
int d[N][N];
PII q[N*N];

void bfs() {
  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

  memset(d, -1, sizeof d);

  int hh = 0, tt = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '1') {
	d[i][j] = 0;
	q[++tt] = {i, j};
      }

  while (hh <= tt) {
    auto t = q[hh++];
    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1) {
	d[x][y] = d[t.first][t.second] + 1;
	q[++tt] = {x, y};
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> g[i];
  bfs();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << d[i][j] << " ";
    cout << endl;
  }
  return 0;
}
