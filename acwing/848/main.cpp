#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N], hh, tt = -1;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort() {
  for (int i = 1; i <= n; i++)
    if (d[i] == 0) q[++tt] = i;

  while (tt >= hh) {
    int t = q[hh++];
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      d[j] --;
      if (d[j] == 0) q[++tt] = j;
    }
  }

  return tt == n-1;
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m--) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    d[y] ++;
  }

  if (topsort()) {
    for (int i = 0; i < n; i++) cout << q[i] << " ";
  } else puts("-1");

  return 0;
}
