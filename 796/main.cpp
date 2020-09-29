#include <iostream>

using namespace std;

const int N = 1010;

int n, m, p;
int q[N][N], s[N][N];


int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) 
      cin >> q[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] = q[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
  while (p--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1] << endl;
  }
}
