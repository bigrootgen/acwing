#include <iostream>

using namespace std;

const int N = 1000010;

int n;
int st[N], s[N];

void dfs(int t) {
  if (!t) {
    for (int i = n; i >= 1; i--) cout << s[i] << " ";
    cout << endl;
  }
  for (int i = 1; i <= n; i++)
    if (!st[i]) {
      s[t] = i;
      st[i] = 1;
      dfs(t-1);
      st[i] = 0;
    }
}

int main() {
  cin >> n;
  dfs(n);
}
