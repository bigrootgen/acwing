#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh = 0, tt = 0;

void pt() {
  cout << "table: ";
  for (int i = hh; i < tt; i++)
	  cout << q[i] << " ";
  cout << endl;
}

int main() {
  int m;
  cin >> m;
  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "push") cin >> x, q[tt++] = x;
    else if (op == "pop") hh++;
    else if (op == "empty") {
      if (tt - hh > 0) cout << "NO" << endl;
      else cout << "YES" << endl;
    }
    else cout << q[hh] << endl;
  }

  return 0;
}
