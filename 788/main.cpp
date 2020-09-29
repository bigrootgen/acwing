#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int q[N];
int tp[N];

int merge_sort(int l, int r) {
  if (l >= r) return 0;
  int mid = l + r >> 1;
  int res = merge_sort(l, mid) + merge_sort(mid+1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) {
      res += j - mid - 1;
      tp[k++] = q[i++];
    }else {
      tp[k++] = q[j++];
    } 
  }
  while (i <= mid) res += j - mid - 1, tp[k++] = q[i++]; 
  while (j <= r) tp[k++] = q[j++];
  for (int i = l; i <= r; i++) q[i] = tp[i];
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> q[i];

  cout << merge_sort(0, n-1) << endl;
}
