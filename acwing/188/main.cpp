#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 210;

char g[N][N];
int d[N][N];
PII q[N * N];
int n, m;

int bfs(int sx, int sy) {

  memset(d, -1, sizeof d);

  int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
  
  int hh = 0, tt = -1;
  q[++tt] = {sx, sy};
  d[sx][sy] = 0;

  while (hh <= tt) {
    auto t = q[hh++];
    
    for (int i = 0; i < 8; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '*' && d[x][y] == -1) {
	q[++tt] = {x, y};
	d[x][y] = d[t.first][t.second] + 1;
       	if (g[x][y] == 'H') return d[x][y];
      }
    }
  }
  
  return -1;
}

int main() {
  cin >> m >> n;

  int sx, sy;
  
  for (int i = 0; i < n; i++) cin >> g[i];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'K') sx = i, sy = j;
    }
  
  cout << bfs(sx, sy) << endl;
  
  return 0;
