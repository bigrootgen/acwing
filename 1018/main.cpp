// f[i][j]: 商人到达（i, j）位置所需要的最小费用
// f[i][j] = min(f[i-1][j], f[i][j-1]) + a[i][j] default f[i][j] = INF

#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int a[N][N];
int f[N][N];

int main() {
  int n;
  cin >> n;
  memset(f, 0x3f, sizeof f);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (i == 0 && j == 0) f[i][j] = a[i][j];
      else {
	if (i-1 >= 0) f[i][j] = min(f[i][j], f[i-1][j]+a[i][j]);
	if (j-1 >= 0) f[i][j] = min(f[i][j], f[i][j-1]+a[i][j]);
      }
    }
  cout << f[n-1][n-1] << endl;
  return 0;
}

