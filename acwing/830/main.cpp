#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt = -1;

int main() {
  cin >> n;
  while (n--) {
    int x;
    cin >> x; 
    while (stk[tt] >= x && tt >= 0) tt--;
    if (tt >= 0) {
      cout << stk[tt] << " ";
    } else {
      cout << -1 << " ";
    }
    stk[++tt] = x;
  }

  return 0;
}
