#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int q[N], s[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> q[i], s[i] = q[i] - q[i-1];

  while (m--) {
    int l, r, c;
    cin >> l >> r >> c;
    s[l] += c;
    s[r+1] -= c;
  }

  for (int i = 1; i <= n; i++) s[i] += s[i-1], cout << s[i] << ' ';
  
  return 0;
}
