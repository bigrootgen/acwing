#include <iostream>

using namespace std;

const int N = 100010;

pair<string, int> a[N];
int n, m;

int calc(int idx, int val) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i].second >> idx & 1;
    string op = a[i].first;
    if (op == "AND") res &= x;
    else if (op == "OR") res |= x;
    else res ^= x;
  }
  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) 
    cin >> a[i].first >> a[i].second;
  int in = 0, ans = 0;
  for (int i = 29; i >= 0; i--) {
    int res0 = calc(i, 0);
    int res1 = calc(i, 1);
    if (in + (1 << i) <= m && res0 < res1)
      in += 1 << i, ans += 1 << i;
    else
      ans += res0 << i;
  }
  cout << ans << endl;
  return 0;
}
