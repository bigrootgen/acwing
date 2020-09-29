#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;
vector<int> path;

void dfs(int n) { // dfs(n):  还有0-n供我们选择
  if (path.size() >= m) { // 问题边界
    for (int i = 0; i < path.size(); i++)  cout << path[i] << " ";
    cout << endl;
    return ;
  }
  else if (path.size() + n < m) return; // 剪枝
  dfs(n-1);
  path.push_back(n);
  dfs(n-1);
  path.pop_back();
}

int main() {
  cin >> n >> m;
  dfs(n);
}
