#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 510;

int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int bfs() {
  memset(dist, 0x3f, sizeof dist);
  memset(st, 0, sizeof st);
  dist[0][0] = 0;
  deque<PII> q;
  q.push_back({0, 0});

  char cs[] = "\\/\\/";
  int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
  int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};

  while (q.size()) {
    auto t = q.front();
    q.pop_front();

    int x = t.first, y = t.second;
    if (st[x][y]) continue;
    st[x][y] = true;

    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      int ca = x + ix[i], cb = y + iy[i];
      if (a >= 0 && a <= n && b >= 0 && b <= m) {
	int d = dist[x][y] + (g[ca][cb] != cs[i]);
	if (d < dist[a][b]) {
	  dist[a][b] = d;
	  if (g[ca][cb] != cs[i]) q.push_back({a, b});
	  else q.push_front({a, b});
	}
      }
    }
  }

  return dist[n][m];
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    int t = bfs();
    if (t == 0x3f3f3f3f) puts("NO SOLUTION");
    else cout << t << endl;
  }
  return 0;
}
