// f[i, j] = f[i-1, j] + f[i-1, j-v[i]]

#include <iostream>

using namespace std;

const int N = 100010;

int f[N], n, m;

int main() {
  cin >> n >> m;
  f[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> v;
    for (int j = m; j >= 0; j--)
      f[j] = f[j] + f[j-v[i]];
  }
  cout << f[m] << endl;
  return 0;
}
