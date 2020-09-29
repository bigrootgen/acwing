#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const int N = 510;

int n, m;
char g[N][N];
int d[N][N];
bool st[N][N]; // 元素可能多次入队，即使有d[][]也可能有更短距离入队

int bfs() {
  char cs[] = "\\/\\/";
  int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1}; // map from pos to next pos
  int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1}; // map from next pos to g char
  memset(st, 0, sizeof st);
  memset(d, 0x3f, sizeof d);
  
  deque<PII> q;
  q.push_back({0,0});
  st[0][0] = true;

  while (q.size()) {
    auto t = q.front();
    q.pop_back();

    int x = t.first, y = t.second;

    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a >= 0 && a < n && b >= 0 && b < m) {
	int ga = x + ix[i], gb = y + iy[i];
	int w = (g[ga][gb] != cs[i]);
	int d = d[x][y] + w;
	if (d <= d[a][b]) {
	  d[a][b] = d;
	  if (!st[a][b]) {
	    if (!w) q.push_front({a, b});
	    else q.push_back({a, b});
	  }
	}
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    if (n + m & 1) puts ("NO SOLUTION");
    else {
      for (int i = 0; i < n; i++) cin >> g[i];
      cout << bfs() << endl;
    }
    return 0;
  }
}
