#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
const int M = 100010;

struct {
  int a, b, w;
}edges[M];

int n, m, k;
int d[N];
int last[N];

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges[i] = {x, y, z};
  }
  
  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  for (int i = 0; i < k; i++) {
    memcpy(last, d, sizeof d);
    for (int j = 0; j < m; j++) {
      auto e = edges[j];
      int a = e.a, b = e.b, w = e.w;
      d[b] = min(d[b], last[a] + w);
    }
  }
  
  if (d[n] > 0x3f3f3f3f/2) puts ("impossible");
  else cout << d[n] << endl;

  return 0;
}
