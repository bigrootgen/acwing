#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

char g[N][N];
bool st[N][N];
int n, m;
int cnt;

void dfs(int x, int y) {
  st[x][y] = true;
  cnt ++;
  int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
  for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && g[a][b] == '.')
      dfs(a, b);
  }
}

int main() {
  while (cin >> m >> n, n | m) {
    memset(st, 0, sizeof st);
    cnt = 0;
    for (int i = 0; i < n; i++) cin >> g[i];
    int x, y;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) 
	if (g[i][j] == '@') x = i, y = j;
    dfs(x, y);
    cout << cnt << endl;
  }
  return 0;
}
