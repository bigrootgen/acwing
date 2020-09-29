#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

// f[i][0]: i不参加舞会的子树最大快乐 f[i][1]: i参加舞会的子树最大快乐
// f[i][0] = sum(max_son(f[i->son][0], max[i->son][1]))
// sum=0
// f[i][0] = sum(max(f[j][0], f[j][1]) for i->j)
// f[i][1] = sum(f[j][0]) for i->j

int n;
int h[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];
bool has_fa[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
  f[u][1] = happy[u];

  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    dfs(j);
    f[u][1] += f[j][0];
    f[u][0] += max(f[j][0], f[j][1]);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> happy[i];

  memset(h, -1, sizeof h);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    add(b, a);
    has_fa[a] = true;
  }

  int root = 1;
  while (has_fa[root]) root++;

  dfs(root);

  cout << max(f[root][0], f[root][1]) << endl;
  return 0;
}
