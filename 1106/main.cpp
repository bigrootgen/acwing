#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n;
int g[N][N];
int st[N][N];
PII q[N * N];
bool has_higher, has_lower;
int peak, valley;

void bfs(int sx, int sy) {
  int hh = 0,  tt = -1;
  q[++tt] = {sx, sy};
  st[sx][sy] = true;

  while (hh <= tt) {
    auto t = q[hh++];
    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++)
	if (i|j) { // 经典判定
	  int x = t.first + i, y = t.second + j; // 经典位移
	  if (x >= 0 && x < n && y >= 0 && y < n) { // 经典判定
	    if (g[x][y] != g[sx][sy]) {
	      if (g[x][y] > g[sx][sy]) has_higher = true;
	      else has_lower = true;
	    }
	    else if (!st[x][y]) {
	      q[++tt] = {x, y};
	      st[x][y] = true;
	    }
	  }
	}
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> g[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (!st[i][j]) {
	has_higher = false, has_lower = false;
	bfs(i, j);
	if (!has_higher) valley++;
	if (!has_lower) peak++;
      }
    }
  cout << valley << " " << peak << endl;
  return 0;
}
