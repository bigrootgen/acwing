// f[i, j] = max(f[i-1, j], f[i-1, j-v[i][k] + w[i][k]]  0 <= k <= s[i]
#include <iostream>

using namespace std;

const int N = 110;

int v[N][N], w[N][N], s[N];
int dp[N];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 1; j <= s[i]; j++) cin >> v[i][j] >> w[i][j];
  }

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--)
      for (int k = 1; k <= s[i]; k++)
	if (j >= v[i][k])
	  dp[j] = max(dp[j], dp[j-v[i][k]] + w[i][k]);

  cout << dp[m] << endl;
  return 0;
}
