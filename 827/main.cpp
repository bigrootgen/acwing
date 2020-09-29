#include <iostream>

using namespace std;

const int N = 100010;

int m;
int l[N], r[N], e[N], idx;

void pt() {
  cout << "table: ";
  for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
  cout << endl;
}

void init() {
  l[1] = 0;
  r[0] = 1;
  idx = 2;
}

void remove(int a) {
  r[l[a]] = r[a];
  l[r[a]] = l[a];
}

void insert(int a, int x) {
  e[idx] = x;
  l[idx] = a, r[idx] = r[a];
  l[r[a]] = idx, r[a] = idx++;
}

int main() {
  init();
  cin >> m;
  while (m--) {
    string op;
    int k, x;
    cin >> op;
    if (op == "L") cin >> x, insert(0, x);
    else if (op == "R") cin >> x, insert(l[1], x);
    else if (op == "D") cin >> k, remove(k+1);
    else if (op == "IL") cin >> k >> x, insert(l[k+1], x);
    else cin >> k >> x, insert(k+1, x);
  }

  for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
  cout << endl;

  return 0;
}
