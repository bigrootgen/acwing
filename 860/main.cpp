#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;
int color[N];
int n, m;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int t, int c) {
  color[t] = c;
  for (int i = h[t]; i != -1; i = ne[i]) {
    int j = e[i];
    if (color[j] == c) return false;
    else if (!color[j]) {
      if (!dfs(j, 3-c)) return false;
    }
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

  
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (!color[i]) {
      if (!dfs(i, 1)) {
	flag = false;
	break;
      }
    }
  }
  if (flag) puts("Yes");
  
return 0;
}
