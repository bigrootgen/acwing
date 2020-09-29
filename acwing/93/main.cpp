#include <iostream>
#include <cstring>

using namespace std;

const int N = 20;
const int M = 1 << 20;

int n;
int f[M][N], weight[N][N];
// f[state][j]: state表示哪些点走过了，j表示目前停在哪个点上
// f[state][j] = f[state_k][k] + weight[k][j], for all k st. state_k = state 除掉j之后的集合, state_k包含k


int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> weight[i][j];
  memset(f, 0x3f, sizeof f);
  f[1][0] = 0;

  for (int i = 0; i < 1 << n; i++)
    for (int j = 0; j < n; j++)
      if (i >> j & 1)
	for (int k = 0; k < n; k++)
	  if (i - (1 << j) >> k & 1)
	    f[i][j] = min(f[i][j], f[i-(1 << j)][k] + weight[k][j]);

  cout << f[(1 << n) - 1][n-1] << endl;
  return 0;
}
