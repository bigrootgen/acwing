#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
queue<int> q;
bool st[N];

void add(int a, int b, int v) {
  e[idx] = b, ne[idx] = h[a], w[idx] = v, h[a] = idx++;
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    add(x, y, z);
  }

  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  q.push(1);
  while (q.size()) {
    int t = q.front();
    q.pop();

    st[t] = false;
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (d[j] > d[t] + w[i]) {
        d[j] = d[t] + w[i];
        if (!st[j]) st[j] = true, q.push(j);
      }
    }
  }

  if (d[n] > 0x3f3f3f3f/2) cout << "impossible" << endl;
  else cout << d[n] << endl;

  return 0;
}
