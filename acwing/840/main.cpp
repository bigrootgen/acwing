#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int n;
int h[N];

int find(int x) {
  int k = (x % N + N) % N;
  while (h[k] != x && h[k] != null) {
    k++;
    if (k == N) k = 0;
  }
  return k;
}

int main() {
  memset(h, 0x3f, sizeof h);
  cin >> n;
  while (n--) {
    char op[2];
    int x;
    scanf ("%s", op);
    cin >> x;
    if (op[0] == 'I') {
      h[find(x)] = x;
    } else {
      int res = h[find(x)];
      if (res != null) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}
