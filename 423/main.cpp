#include <iostream>

using namespace std;

const int N = 1010, M = 110;

int f[N];
int n, m;

int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    int v, w;
    cin >> v >> w;
    for (int j = m; j >= v; j--)
      f[j] = max(f[j], f[j-v] + w);
  }
  cout << f[m] << endl;
  return 0;
}

