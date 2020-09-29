#include <iostream>

using namespace std;

const int N = 5010;

int s[N][N];
int n, R;

int main() {
  cin >> n >> R;
  while (n--) {
    int x, y, w;
    s[x][y] += w;
  }
  for (int i = 1; i < N; i++)
    for (int j = 1; j < N; j++)
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + s[i][j];
  int res = 0;
  for (int i = R; i < N; i++)
    for (int j = R; j < N; j++)
      res = max(res, s[i][j] - s[i-R][j] - s[i][j-R] + s[i-R][j-R]);
  cout << res << endl;
  return 0;
}
