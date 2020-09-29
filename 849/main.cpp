#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];

void add(int a, int b, int v) {
  e[idx] = b, ne[idx] = h[a], w[idx] = v, h[a] = idx++;
}

int dijkstra() {
  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, 1});

  while (q.size()) {
    auto t = q.top();
    q.pop();
    
    int ver = t.second, distance = t.first;
    
    if (st[ver]) continue;
    st[ver] = true;
    
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (d[j] > d[ver] + w[i]) d[j] = d[ver] + w[i], q.push({d[j], j});
  }
}

if (d[n] == 0x3f3f3f3f) return -1;
return d[n];
}

int main() {
  cin >> n >> m;
memset(h, -1, sizeof h);
while (m--) {
  int x, y, z;
  cin >> x >> y >> z;
add(x, y, z);
}

cout << dijkstra() << endl;
			}
