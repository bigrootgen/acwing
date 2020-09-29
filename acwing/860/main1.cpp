#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;
bool color[N];
bool st[N];
int n, m;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int t) {
  int c = color[t];
  for (int i = h[t]; i != -1; i = ne[i]) {
    int j = e[i];
    if (st[j] && color[j] == c) return false;
    if (st[j]) continue;
    color[j] = !c;
    st[j] = true;
    if (!dfs(j)) return false;
  }
  return true;
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  // dfs
  st[1] = true;
  if (dfs(1)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
