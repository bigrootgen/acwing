#include <iostream>

using namespace std;

const int R = 110, C = 110;

int f[R][C];
int a[R][C];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
	cin >> a[i][j];
	f[i][j] = a[i][j];
	if (i-1 >= 0) f[i][j] = max(f[i][j], f[i-1][j] + a[i][j]);
	if (j-1 >= 0) f[i][j] = max(f[i][j], f[i][j-1] + a[i][j]);
      }
    cout << f[r-1][c-1] << endl;
  }
  return 0;
}
