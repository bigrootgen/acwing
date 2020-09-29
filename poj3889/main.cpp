#include <iostream>
#include <vector>

using namespace std;

vector<int> path;

int n, m;

void dfs(int t) {
  if (path.size() >= m) {
    for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
    cout << endl;
    return ;
  }
  else if (path.size() + t < m) return ;
  path.push_back(t);
  dfs(t-1);
  path.pop_back();
  dfs(t-1);
}

int main() {
  cin >> n >> m;
  dfs(n);
}
