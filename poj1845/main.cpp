#include <iostream>

using namespace std;

const int mod = 9901; 

int qmi(int a, int p) {
  int res = 1;
  for (; p; p>>=1) {
    if (p & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

int sum(int a, int p) {
  if (p == 0) return 1;
  else if (p & 1) return (1 + qmi(a,(p>>1)+1)) * sum(a, p>>1) % mod;
  else return (p % mod * sum(a, p-1) % mod + 1) % mod;
}

int main() {
  int a, b;
  cin >> a >> b;
  int res = 1;
  for (int i = 2; i <= a; i++) {
    int s = 0;
    while (a % i == 0) {
      s ++;
      a /= i;
    }
    res = res * sum(i, s * b) % mod;
  }
  if (!a) res = 0;
  cout << res << endl;
  
  return 0;
}
