#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;

int s[N];
int dp[N];
int n;

// (i, j)  (1+i-1)*(i-1)/2+j = (i)*(i-1)/2+j
// 左父节点：(i-1, j-1) ) (i-1)*(i-2)/2+j-1 j>=1
// 右父节点：(i-1, j) (i-1)*(i-2)/2+j  j<=i-1

int main() {
  cin >> n;
  for (int i = 1; i <= n*(n+1)/2; i++) cin >> s[i], dp[i]=-1e9;
  dp[1] = s[1];
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      if (j > 1) dp[i * (i-1) /2 + j] = max(dp[(i-1)*(i-2)/2+j-1]+s[i*(i-1)/2+j], dp[i*(i-1)/2+j]);
      if (j < i) dp[i * (i-1)/2 +j] = max(dp[(i-1)*(i-2)/2+j]+s[i*(i-1)/2+j], dp[i*(i-1)/2+j]);
    }
  int res = 0;
  for (int j = 1; j <= n; j++) res = max(res, dp[n*(n-1)/2+j]);
  cout << res << endl;
  return 0;
}
  
