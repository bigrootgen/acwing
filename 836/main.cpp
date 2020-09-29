#include <iostream>

using namespace std;

const int N = 1000010;

int p[N], idx;
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) p[i] = i;

  while (m--) {
    char op[2];
    int a, b;
    scanf ("%s%d%d", op, &a, &b);
    if (*op == 'M') {
      while (p[a] != a) a = p[a];
      while (p[b] != b) b = p[b];
      if (a != b) p[a] = b;
    }else {
      while (p[a] != a) a = p[a];
      while (p[b] != b) b = p[b];
      if (a == b) puts ("Yes"); else puts ("No");
    }
  }
}
