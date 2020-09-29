#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 21;

int n, a[N];
vector<int> grp[N]; int gcnt;
int ans = 0x3f3f3f3f;

int gcd(int a, int b) {
  return b? gcd(b, a%b) : a;
}

bool check(vector<int> grp, int x) {
  for (int i = 0; i < grp.size(); i++)
    if (gcd(grp[i], x) > 1) return false;
  return true;
}

void dfs(int t) {
  if (t == n) {
    ans = min(ans, gcnt);
    return;
  }
  for (int i = 0; i < gcnt; i++) {
    if (check(grp[i], a[t])) {
      grp[i].push_back(a[t]);
      dfs(t+1);
      grp[i].pop_back();
    }
  }
  grp[gcnt++].push_back(a[t]);
  dfs(t+1);
  grp[--gcnt].pop_back();
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0);
  cout << ans << endl;
}
