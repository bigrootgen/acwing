#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;

int n;
int s[N];
int f[N][N];

int main() {
  cin >> n;
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++) cin >> s[i], f[i][i] = 0;
  for (int i = 1; i <= n; i++) s[i] += s[i-1];

  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= n; j++) {
      if (i < j) {
	for (int k = i; k < j; k++)
	  f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
      }
    }
  cout << f[1][n] << endl;
  return 0;
}
