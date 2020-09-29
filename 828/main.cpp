#include <iostream>

using namespace std;

const int N = 100010;

int m;
int stk[N], tt;

int main() {
  cin >> m;
  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "push") cin >> x, stk[tt++] = x;
    else if (op == "pop") tt--;
    else if (op == "empty") {
      if (!tt) puts("YES");
      else puts("NO");
    }
    else cout << stk[tt-1] << endl;
  }
}
