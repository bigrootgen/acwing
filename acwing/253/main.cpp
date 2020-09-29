#include <iostream>

using namespace std;

const int N = 100010, INF = 1e8;

int n;
struct {int l, r, val, w, size, cnt;}tr[N]; int root, idx;
#define l(x) tr[x].l
#define r(x) tr[x].r
#define val(x) tr[x].val
#define w(x) tr[x].w
#define size(x) tr[x].size
#define cnt(x) tr[x].cnt

void pushup(int p) {
  size(p) = size(l(p)) + size(r(p)) + cnt(p);
}

int get_node(int val) {
  tr[++idx] = {0, 0, val, rand(), 1, 1};
  return idx;
}

void zig(int &p) {
  int t = l(p);
  l(p) = r(t), r(t) = p, p = t;
  pushup(r(p)), pushup(p);
}

void zag(int &p) {
  int t = r(p);
  r(p) = l(t), l(t) = p, p = t;
  pushup(l(p)), pushup(p);
}

void build() {
  get_node(-INF), get_node(INF);
  r(1) = 2;
  root = 1;
  pushup(root);
  if (w(r(root)) > w(root)) zag(root);
}

void insert(int &p, int val) {
  if (!p) p = get_node(val);
  else if (val(p) == val) cnt(p)++;
  else if (val(p) < val) {
    insert(r(p), val);
    if (w(r(p)) > w(p)) zag(p);
  }
  else {
    insert(l(p), val);
    if (w(l(p)) > w(p)) zig(p);
  }
  pushup(p);
}

void remove(int &p, int val) {
  if (!p) return;
  else if (val(p) == val) {
    if (cnt(p) > 1) cnt(p) --;
    else if (!l(p) && !r(p)) p = 0;
    else if (!l(p) || w(r(p)) > w(l(p))) zag(p), remove(l(p), val);
    else zig(p), remove(r(p), val);
  }
  else if (val(p) < val) remove(r(p), val);
  else remove(l(p), val);
  pushup(p);
}

int get_rank(int p, int val) {
  if (!p) return 0;
  else if (val(p) == val) return size(l(p));
  else if (val(p) > val) return get_rank(l(p), val);
  else return size(l(p)) + cnt(p) + get_rank(r(p), val);
}

int get_val(int p, int rank) {
  if (!p) return INF;
  else if (rank < size(l(p))) return get_val(l(p), rank);
  else if (rank < size(l(p)) + cnt(p)) return val(p);
  else return get_val(r(p), rank - size(l(p)) - cnt(p));
}

int get_prev(int p, int val) {
  if (!p) return -INF;
  else if (val(p) >= val) return get_prev(l(p), val);
  else return max(val(p), get_prev(r(p), val));
}

int get_next(int p, int val) {
  if (!p) return INF;
  else if (val(p) <= val) return get_next(r(p), val);
  else return min(val(p), get_next(l(p), val));
}

int main(){
  build();
  cin >> n;
  while (n--) {
    int op, x;
    cin >> op >> x;
    if (op == 1) insert(root, x);
    else if (op == 2) remove(root, x);
    else if (op == 3) cout << get_rank(root, x) << endl;
    else if (op == 4) cout << get_val(root, x) << endl;
    else if (op == 5) cout << get_prev(root, x) << endl;
    else cout << get_next(root, x) << endl;
  }
  return 0;
}
