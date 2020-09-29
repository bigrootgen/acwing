#include <iostream>

using namespace std;

const int N = 1010, M = 110;

int n, m;
int f[N];

int main() {
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    int v, w;
    cin >> v >> w;
    for (int j = m; j >= v; j--)
      if (f[j-v] + w > f[j]) f[j] = f[j-v] + w;
  }
  cout << f[m] << endl;
  return 0;
}


