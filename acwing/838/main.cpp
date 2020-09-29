#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N];

void down(int u) {
  int t = u;
  if (u * 2 <= n && h[t]>= h[u * 2]) t = u * 2;
  if (u * 2 + 1 <= n && h[t] >= h[u * 2 + 1]) t = u * 2 + 1;
  if (u != t) {
    swap(h[t], h[u]);
    down(t);
  }
}

void up(int u) {
  if (u/2 && h[u] <= h[u/2]) swap(h[u], h[u/2]), up(u/2);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> h[i];

  for (int i = n/2; i; i--) down(i);
  while (m--) {
    cout << h[1] << " ";
    h[1] = h[n--];
    down(1);
  }
}
