#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

typedef long long LL;

int n;
int a[N];
int tr[N]; // 支持logn修改，logn求区间和，此处用于记录位于某个区间的值的个数，维护区间统计信息
// sum(y) 返回<=y的值的个数
int Greater[N], lower[N]; // graeter[k]: 1-k-1中，有多少个数大于yk

int lowbit(int x) {
  return x & -x;
}

void add(int x, int c) {
  while (x <= n) tr[x] += c, x += lowbit(x);
}

int sum(int x) {
  int res = 0;
  while (x) res += tr[x], x -= lowbit(x);
  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int y = a[i];
    Greater[i] = sum(n) - sum(y); // a[i]前面有多少个数大于a[i]
    lower[i] = sum(y-1); 
    add(y, 1); 
  }

  memset(tr, 0, sizeof tr);
  LL res1 = 0, res2 = 0;
  for (int i = n; i; i--) {
    int y = a[i];
    res1 += Greater[i] * (LL)(sum(n) - sum(y));
    res2 += lower[i] * (LL)(sum(y-1));
    add(y, 1);
  }

  cout << res1 << res2 << endl;
  return 0;
}
