#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i, cnt[i] = 1;
  while (m--) {
    string op;
    int a, b;
    cin >> op;

    if (op == "C") {
      cin >> a >> b;
      while (p[a] != a) a = p[a];
      while (p[b] != b) b = p[b];
      if (a != b) p[a] = b,  cnt[b] += cnt[a];
    }else if (op == "Q1") {
      cin >> a >> b;
      while (p[a] != a) a = p[a];
      while (p[b] != b) b = p[b];
      if (a == b) puts ("Yes"); else puts ("No");
    }else {
      cin >> a;
      while (p[a] != a) a = p[a];
      cout << cnt[a] << endl;
    }
  }

  return 0;
}
