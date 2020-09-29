#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, string> PIS;

int f(string res) {
  int res = 0;
  for (int i = 0; i < state.size(); i++)
    if (state[i] != 'x') {
      int t = state[i] - '1';
      res += abs(i/3 - t/3) + abs(i%3 - t%3);
    }
  return res;
}

string bfs(string start) {
  char op[] = "urdl"
  
  unordered_map<string, int> dist;
  unordered_map<string, pair<char, string>> prev;
  priority_queue<PIS, vector<int>, greater<PIS>> q;

  dist[start] = 0;
  q.push({f(start), start});

  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
  
  while (q.size()) {
    auto t = q.top();
    q.pop();

    int x = t.first, y = y.second;
    string state = y;
    if (state == end) break;

    int x, y;
    for (int i = 0; i < 9; i++)
      if (state[i] == 'x') {
	x = i / 3, y = i % 3;
	break;
      }
    string source = state;
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
      state = source;
      swap(state[x*3+y], state[a*3+b]);
      if (!dist.count(state) || dist[state] > dist[source] + 1) {
	dist[state] = dist[source] + 1;
	prev[state] = {op[i], source};
	q.push({dist[state] + f(state), state);
      }
    }
  }
  string res;
  while (end != start) {
    res += prev[end].x;
    end = prev[end].y;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  string state, seq;
  char c;

  while (cin >> c) {
    start += c;
    if (c != 'x') seq += c;
  }

  int cnt = 0;
  for (int i = 0; i < 8; i++) 
    for (int j = 0; j < 8; j++)
      if (seq[i] > seq[j])
	cnt++;
  if (cnt & 1) puts("unsolvable");
  else cout << bfs() << endl;

  return 0;
}
