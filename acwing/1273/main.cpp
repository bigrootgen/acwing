#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 200010, M = 18;

int n, m;
int s[N];
int f[N][M];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i], f[i][0] = s[i];

  for (int j = 1; j < M; j++)
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      f[i][j] = f[i][j-1];
      if (i + (1 << j) -1 < n) 
	f[i][j] = max(f[i][j-1], f[i + (1 << j - 1)][j-1]);
    }
  
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    int k = log(b-a+1)/log(2);
    cout << max(f[a][k], f[b-(1 << k) + 1][k]) << endl;
  }

  return 0;
}
