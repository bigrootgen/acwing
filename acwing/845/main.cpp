#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

const int N = 10;

string start;
queue<string> q;
unordered_map<string, int> d;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

inline int find(string s) {
  for (int i = 0; i < 9; i++) if (s[i] == 'x') return i;
}

int bfs() {
  q.push(start);
  d[start] = 0;
  string end = "12345678x";

  while (q.size()) {
    auto t = q.front();
    q.pop();

    if (t == end) return d[t];

    int distance = d[t];
    int k = find(t);
    int x = k/3, y = k%3;
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a < 3 && a >= 0 && b < 3 && b >= 0) {
	swap(t[a*3+b], t[x*3+y]);
	if (!d.count(t)) {
	  q.push(t);
	  d[t] = distance + 1;
	}
	swap(t[a*3+b], t[x*3+y]);
      }
    }
  }
  return -1;
}

int main() {
  char op[2];
  for (int i = 1; i <= 9; i++) {
    cin >> op;
    start += *op;
  }
  cout << bfs() << endl;
  return 0;
}
