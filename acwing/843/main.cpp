#include <iostream>

using namespace std;

const int N = 11;

int board[N][N];
int path[N];
int n;

bool check(int t, int k) {
  bool flag = true;
  for (int i = t; i >= 1; i--) {
    if (path[i] == k || path[i] == k - (t-i) || path[i] == k + (t-i))
      flag = false;
  }
  return flag;
}

void dfs(int t) {
  if (t > n) { // t == n+1
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
	if (path[i] == j) cout << 'Q';
	else cout << '.';
      }
      cout << endl;
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    if (check(t, i)) {
      path[t] = i;
      dfs(t+1);
      path[t] = 0;
    }
  }
}

int main() {
  cin >> n;
  dfs(1);
}
