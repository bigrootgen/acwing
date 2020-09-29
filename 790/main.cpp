#include <bits/stdc++.h>

using namespace std;

const int N  = 100010;

double n;

int main() {
  cin >> n;
  double l = -10000, r = 10000;
  double x;
  while (r - l >= 1e-8) {
    x = (l + r) / 2;
    if (x * x * x >= n) r = x;
    else l = x;
  }

  printf("%.6f", l);

  return 0;
}
