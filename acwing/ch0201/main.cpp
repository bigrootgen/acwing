#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int g[10][10];
int backup[10][10];
int cnt;

void printg() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++)
      cout << g[i][j];
    cout << endl;
  }
  cout << endl;
  return ;
}

bool work(int x) {
  memcpy(g, backup, sizeof backup);
  cnt = 0;
  int dx[] = {0, 1, 0, -1, 0}, dy[] = {1, 0, -1, 0, 0};
  for (int i = 0; i < 5; i++) { 
    for (int j = 0; j < 5; j++) {
      if (x >> j & 1) {
	for (int k = 0; k < 5; k++)
	  g[i+dx[k]][j+dy[k]] ^= 1;
	cout << i << j << endl;
	printg();
	cnt ++;
	// if (cnt > 6) return false;
      }
    }
    x = 0;
    for (int j = 0; j < 5; j++)
      if (g[i][j] == 1) x += 1 << j;
  }
  if (x == 0)  { cout << "--Yes--"; return true;}
  else {cout << "--No--"; return false;}
}

int main() {
  int res = 0x3f3f3f3f;
  
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) cin >> g[i][j];
  memcpy(backup, g, sizeof g);
  
  for (int i = 0; i < 1 << 5; i++) 
    if (work(i)) res = min(res, cnt);
  
  if (res == 0x3f3f3f3f) cout << -1 << endl;
  else cout << res << endl;
  
  return 0;
}
