#include <iostream>

using namespace std;

const int N = 200010;

int v[N], n;
int f[N];

int main() {
  int m;
  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> v[i];

  for (int i = 0; i < n; i++)
    for (int j = m; j >= v[i]; j--) f[j] = max(f[j], f[j-v[i]] + v[i]);

  cout << m-f[m] << endl;
  return 0;
}
