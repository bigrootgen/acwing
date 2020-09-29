// f[i]: 以s[i]结尾的最大子序列长度
// f[i] = max(f[k], f[i]) s[i] > s[k]
#include <iostream>

using namespace std;

const int N = 1010;

int n;
int s[N];
int f[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i], f[i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k < i; k++)
      if (s[i] > s[k])
	f[i] = max(f[i], f[k]+1);
  }
  
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, f[i]);
  cout << res << endl;
  return 0;
}
