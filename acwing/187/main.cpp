#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int a[N], n;
int up[N], down[N];
int ans;

void dfs(int u, int su, int sd) {
  if (su + sd >= ans) return;
  if (u == n) {
    ans = min(ans, su+sd);
    return ;
  }
  int k = 0;
  while (k < su && up[k] >= a[u]) k++;
  if (k < su) {
    int t = up[k];
    up[k] = a[u];
    dfs(u+1, su, sd);
    up[k] = t;
  }
  else {
    up[k] = a[u];
    dfs(u+1, su+1, sd);
  }
  k = 0;
  while (k < sd && down[k] <= a[u]) k++;
  if (k < sd) {
    int t = down[k];
    down[k] = a[u];
    dfs(u+1, su, sd);
    down[k] = t;
  }
  else {
    down[k] = a[u];
    dfs(u+1, su, sd+1);
  }
}

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = n;
    dfs(0, 0, 0);
    cout << ans << endl;
  }
  return 0;
}
