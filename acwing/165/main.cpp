#include <iostream>
#include <algorithm>

using namespace std;

const int N = 21;

int n, w[N];
int gcnt, sz[N];
int m;
int ans = N;

void dfs(int t) {
  if (gcnt >= ans) return;
  if (t == n) {
    ans = gcnt;
    return;
  }
  for (int i = 0; i < gcnt; i++) {
    if (sz[i] + w[t] <= m) {
      sz[i] += w[t];
      dfs(t+1);
      sz[i] -= w[t];
    }
  }
  sz[gcnt++] = w[t];
  dfs(t+1);
  sz[gcnt--] = 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> w[i];
  sort(w, w+n);
  reverse(w, w+n);
  dfs(0);
  cout << ans << endl;
  return 0;
}
