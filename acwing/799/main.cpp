#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], st[N];

int solve() {
  int m = 0;
  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (st[q[i]] >= j) j = st[q[i]] + 1;
    if (i - j + 1 >= m) m = i - j + 1;
    st[q[i]] = i;
  }

  return m;
}

int main() {
  
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> q[i], st[i] = 0;

  cout << solve() << endl;
}
