#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
int q[N];

int find_kth(int l, int r) {
  if (l >= r) return q[l];
  int i = l - 1, j = r + 1;
  int x = q[l + r >> 1];
  while (i < j) {
    while (q[++i] < x);
    while (q[--j] > x);
    if (i < j) swap(q[i], q[j]);
  }
  if (j + 1 >= k) return find_kth(l, j);
  else return find_kth(j+1, r);
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  cout << find_kth(0, n-1) << endl;
}
