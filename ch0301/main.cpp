#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n;
vector<int> path;

void dfs(int n) {
  if (!n) {
    for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
    cout << endl;
    return;
  }
  path.push_back(n);
  dfs(n-1);
  path.pop_back();
  dfs(n-1);
}

int main() {
  cin >> n;
  dfs(n);
}

