#include <iostream>
#include <cstring>

using namespace std;

const int N = 12;

int n, m;
long long  f[N][1 << N];
long long  in_s[1 << N];

int main() {
  while (cin >> n >> m, n || m) {
    for (int i = 0; i < 1 << n; i++) {
      bool has_odd = 0, cnt = 0;
      for (int j = 0; j < n; j++) {
	if (i >> j & 1) has_odd |= cnt, cnt = 0;
	else cnt ^=  1;
      }
      in_s[i] = has_odd | cnt ? 0 : 1;
    }

    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 0; j < 1 << n; j++)
	for (int k = 0; k < 1 << n; k++) 
	  if ((j & k) == 0 && in_s[j | k]) f[i][j] += f[i-1][k];
    cout << f[m][0] << endl;
  }
  return 0;
}
