#include <iostream>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;
int match[N];
int st[N];
int n1, n2, m;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int t) {
  for (int i = h[t]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      st[j] = true;
      if (!match[j] || find(match[j])) {
	match[t] = j;
	return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> n1 >> n2 >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }

  int res = 0;
  for (int i = 1; i <= n1; i++) {
    if (find(i)) res++;
  }

  cout << res << endl;
  return 0;
}
