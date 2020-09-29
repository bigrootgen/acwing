#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;
char str[N];
int n;

void insert(char* str) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int x = str[i] - 'a';
    if (!son[p][x]) son[p][x] = ++idx;
    p = son[p][x];
  }
  cnt[p] ++;
}

int query(char* str) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int x = str[i] - 'a';
    if (!son[p][x]) return 0;
    p = son[p][x];
  }
  return cnt[p];
}

int main() {
  cin >> n;
  while (n--) {
    string op; 
    cin >> op;
    if (op == "I") {
      cin >> str;
      insert(str);
    }else {
      cin >> str;
      cout << query(str) << endl;
    }
  }
}
