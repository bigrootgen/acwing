#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10;

char g[2][4];
unordered_map<string, int> d;
unordered_map<string, pair<char, string>> pre;

string get() {
  string res;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++)
      res += g[i][j];
  return res;
}

void set(string state) {
  int k = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++)
      g[i][j] = state[k++];
}

string move0(string state) {
  set(state);
  for (int i = 0; i < 4; i++)
    swap(g[0][i], g[1][i]);
  return get();
}

string move1(string state) {
  set(state);
  int v[2];
  for (int i = 0; i < 2; i++) {
    v[i] = g[i][3];
    for (int j = 3; j >= 1; j--) {
      g[i][j] = g[i][j-1];
    }
    g[i][0] = v[i];
  }
  return get();
}

string move2(string state) {
  set(state);
  int v = g[0][1];
  g[0][1] = g[1][1];
  g[1][1] = g[1][2];
  g[1][2] = g[0][2];
  g[0][2] = v;
  return get();
}

int bfs(string start, string end) {
  if (start == end) return 0;
  
  queue<string> q;
  q.push(start);
  d[start] = 0;

  while (!q.empty()) {
    auto t = q.front();
    q.pop();

    string m[3];
    m[0] = move0(t);
    m[1] = move1(t);
    m[2] = move2(t);


    for (int i = 0; i < 3; i++)
      if (!d.count(m[i])) {
	d[m[i]] = d[t] + 1;
	pre[m[i]] = {'A'+i, t};
	q.push(m[i]);
	if (m[i] == end) return d[end];
      }
  }
  return -1;
}

int main() {
  string start = "12345678", end;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++)
      cin >> g[i][j], end += g[i][j];
  cout << bfs(start, end) << endl;
  string res;
  while (end != start) {
    res += pre[end].first;
    end = pre[end].second;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
}
