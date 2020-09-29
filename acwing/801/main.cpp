#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N];

int lowbit(int n) {
  return n & -n;
}

int main() {
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    
    int m = 0;
    while (lowbit(x)) {
      x = x - lowbit(x);
      m ++;
    }

    cout << m << " " ;
  }

  return 0;
}
