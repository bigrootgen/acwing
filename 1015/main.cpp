#include <iostream>

using namespace std;

const int R = 110, C = 110;

int a[R][C];
int f[R][C];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int r, c;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
	cin >> a[i][j] >> f[i][j];
      }

    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
	if (j >= 1)
	  f[i][j] = max(f[i][j], f[i][j-1]);
	if (i >= 1)
	  f[i][j] = max(f[i][j], f[i-1][j]);
      }
    cout << f[r-1][c-1] << endl;
  }
  return 0;
}
