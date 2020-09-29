#include <iostream>
#include <string>

using namespace std;

const int N = 21;

int n;
string word[N];
int ans;
int g[N][N];
int cnt[N];

void dfs(string dragon, int last) {
  ans = max((int)dragon.size(), ans);
  cnt[last] --;
  for (int i = 0; i < n; i++)
    if (cnt[i] && g[last][i]) {
      dfs(dragon.substr(0, dragon.size() - g[last][i]) + word[i], i);
    }
  cnt[last] ++;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> word[i], cnt[i] = 2;
  char start;
  cin >> start;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      string a = word[i], b = word[j];
      for (int k = 1; k < min(a.size(), b.size()); k++)
	if (a.substr(a.size() - k, k) == b.substr(0, k)) {
	  g[i][j] = k;
	  break;
	}
    }
    
  for (int i = 0; i < n; i++)
    if (word[i][0] == start)
      dfs(word[i], i);

  cout << ans << endl;
  return 0;
}
