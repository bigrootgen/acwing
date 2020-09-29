#include <iostream>

using namespace std;

const int N = 300010;

int n, k;
int a[N];
int q[N], hh, tt = -1;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    while (a[q[tt]] >= a[i] && tt >= hh) tt--;
    q[++tt] = i;
    if (i - q[hh] + 1 > k) hh++;
    if (i + 1 >= k) cout << a[q[hh]] << " ";
  }
  cout << endl;

  hh = 0, tt = -1;
  for (int i = 0; i < n; i++) {
    while (a[q[tt]] <= a[i] && tt >= hh) tt--;
    q[++tt] = i;
    if (i - q[hh] + 1 > k) hh++;
    if (i + 1 >= k) cout << a[q[hh]] << " ";
  }
  cout << endl;

  return 0;
}

