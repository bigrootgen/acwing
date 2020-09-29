#include <iostream>

using namespace std;

const int N = 1010;

int a[N], n;
int f[N];
int q[N], cnt;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
    res = max(res, f[i]);
  }
  cout << res << endl;
  for (int i = 0; i < n; i++) {
    int k = 0;
    while (k < cnt && q[k] < a[i]) k++;
    if (k == cnt) q[cnt++] = h[i];
    else q[k] = h[i];
  }
  cout << res << endl;
  cout << cnt << endl;
  return 0;
}
