#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, p;
int q[N];

int find_k(int l, int r, int k) {
  if (l >= r && q[l] == k) return l;
  if (l >= r && q[l] != k) return -1;
  int mid = l + r >> 1;
  if (q[mid] >= k) return find_k(l, mid, k);
  else return find_k(mid+1, r, k);
}

int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  while (p--) {
    int k;
    cin >> k;
    int l = find_k(0, n-1, k);
    int r = l;
    while (q[++r] == k); r--;
    cout << l << " " << r << endl;
  }

  return 0;
}
