#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int q[N];
int tp[N];

void merge_sort(int l, int r) {
  if (l >= r) return ;
  int mid = l + r >> 1;
  merge_sort(l, mid);
  merge_sort(mid+1, r);

  int i = l, j = mid + 1, k = l; 
  while (i <= mid && j <= r) {
    if (q[i] < q[j]) tp[k++] = q[i++];
    else tp[k++] = q[j++];
  }
  while (i <= mid) tp[k++] = q[i++];
  while (j <= r) tp[k++] = q[j++];
  for (int i = l; i <= r; i++) q[i] = tp[i];
  
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> q[i];

  merge_sort(0, n-1);

  for (int i = 0; i < n; i++) cout << q[i] << " ";
}
