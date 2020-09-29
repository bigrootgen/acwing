#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n;
bool st[N];
vector<int> path;

void dfs(int t) {
  if (!t) {
    for (int i = 0; i < n; i++) cout << path[i] << " ";
    cout << endl;
    return ;
  }
  for (int i = 1; i <= n; i++) {
    if (st[i]) continue;
    st[i] = true;
    path.push_back(i);
    dfs(t-1);
    path.pop_back();
    st[i] = false;
  }
  return ;
}

int main() {
  cin >> n;
  dfs(n);
}
