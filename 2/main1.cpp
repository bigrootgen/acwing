#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int w[N], v[N];
int f[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 0; j--) {
      if (j < w[i]) f[i][j] = f[i-1][j];
      else f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i]);
    }
  }
  cout << f[n][m] << endl;
  return 0;
}
