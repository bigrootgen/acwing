
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int q[N];

void qsort(int l, int r) {
  if (l >= r) return ;
  int x = q[l + r >> 1];
  int i = l - 1, j = r + 1;
  while (i < j) {
    while (q[++i] < x);
    while (q[--j] > x);
    if (i < j) swap(q[i], q[j]);
  }
  // 循环结束后，j左边的<=x, j右边的>=x
  qsort(l, j);
  qsort(j+1, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  qsort(0, n-1);

  for (int i = 0; i < n; i++) cout << q[i] << " ";

  return 0;
}
