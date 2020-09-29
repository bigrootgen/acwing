#include <iostream>

using namespace std;

const int N = 1010;

typedef pair<int, int> PII;
#define x first
#define y second

int n, m;
char g[N][N];
bool st[N][N];
PII q[N*N];

void bfs(int sx, int sy) { // flood fill
  int hh = 0, tt = -1;
  q[++tt] = {sx, sy};
  st[sx][sy] = true;
  while (hh <= tt) {
    auto t = q[hh++];
    for (int i = t.x - 1; i <= t.x + 1; i++)
      for (int j = t.y - 1; j <= t.y + 1; j++) {
	if (!st[i][j] && g[i][j] == 'W' && i >= 0 && i < n && j >= 0 && j < m && !(i==t.x && j==t.y)) {
	  q[++tt] = {i, j};
	  st[i][j] = true;
	}
      }
  }
  return ;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> g[i];
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!st[i][j] && g[i][j] == 'W') bfs(i, j), cnt++;
  cout << cnt << endl;
  return 0;
}
