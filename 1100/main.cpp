#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, k;
int d[N];
int q[N];

void bfs(int x) {
  memset(d, -1, sizeof d);
  int hh = 0, tt = -1;
  q[++tt] = x;
  d[x] = 0;

  while (hh <= tt) {
    int t = q[hh++];
    int i = t-1;
    if (d[i] == -1) d[i] = d[t] + 1, q[++tt] = i;
    i =  t+1;
    if (d[i] == -1) d[i] = d[t] + 1, q[++tt] = i;
    i = t*2;
    if (d[i] == -1) d[i] = d[t] + 1, q[++tt] = i;
    if (t+1 == k || t-1 == k || t*2 == k) return ;
  }
}

int main() {
  cin >> n >> k;
  bfs(n);
  cout << d[k] << endl;
  return 0;
}
