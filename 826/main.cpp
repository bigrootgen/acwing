#include <iostream>

using namespace std;

const int N = 100010;

int h, e[N], ne[N], idx;

void init() {
  h = -1;
  idx = 0;
}

void insert_from_head(int x) {
  e[idx] = x;
  ne[idx] = h;
  h = idx++;
}

void insert(int k, int x) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx++;
}

void remove(int k) {
  ne[k] = ne[ne[k]];
}

int main() {
  int m;
  cin >> m;

  init();

  while (m--) {
    int k, x;
    char op;
    
    cin >> op;
    if (op == 'H') {
      cin >> x;
      insert_from_head(x);
    } else if (op == 'D')  {
      cin >> k;
      if (!k) h = ne[h];
      else remove(k - 1);
    } else {
      cin >> k >> x;
      insert(k - 1, x);
    }

  }

  int t = h;
  while (t!=-1) {
    cout << e[t] << " ";
    t = ne[t];
  } 
}
