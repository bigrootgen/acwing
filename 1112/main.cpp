#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

char g[N][N];
bool st[N][N];
int n;
int ax, ay, bx, by;

bool bfs(int x, int y) {
  if (g[x][y] == '#') return false;
  if (x == bx && y == by) return true;
  st[x][y] = true;
  int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
  for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (a >= 0 && a < n && b >= 0 && b < n && g[a][b] != '#' && !st[a][b]) {
      if (bfs(a, b)) return true;
    }
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(st, 0, sizeof st);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> g[i];
    cin >> ax >> ay >> bx >> by;
    if (bfs(ax, ay)) puts("YES");
    else puts("NO");
  }

  return 0;
}
