#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge{
  int a, b, w;

  bool operator< (const Edge &W) const {
    return w < W.w;
  }
}edges[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[i] = {a, b, w};
  }

  for (int i = 1; i <= n; i++) p[i] = i;

  sort(edges, edges+m);

  int sum = 0, cnt = 0;
  for (int i = 0; i < m; i++) {
    auto e = edges[i];
    int a = e.a, b = e.b, w = e.w;
    if (find(a) == find(b)) continue;
    p[find(a)] = find(b);
    sum += w;
    cnt++;
  }
  if (cnt < n-1) {cout << "impossible" << endl; return 0;}
  cout << sum << endl;
  return 0;
}
