#include <iostream>

using namespace std;

const int N = 100010, p = 131;

int n, m;
char s[N];
int h[N], q[N];

int query(int l, int r) {
  return h[r] - h[l-1] * q[r - l + 1];
}

int main() {
  cin >> n >> m;
  cin >> s+1;
  q[0] = 1;
  for (int i = 1; i <= n; i++) h[i] = h[i-1] * p + s[i], q[i] = q[i-1] * p;
  while (m--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (query(l1, r1) == query(l2, r2)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}

