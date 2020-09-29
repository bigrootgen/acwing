#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

vector<int> div(vector<int> A, int b, int& r) {
  vector<int> C;
  int t = 0;
  for (int i = A.size() - 1; i >= 0; i--) {
    t = A[i] + t * 10;
    if (t >= b) {
      C.push_back(t/b);
      t %= b;
    }else{
      C.push_back(0);
    }
  }
  r = t;
  reverse(C.begin(), C.end());
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}

int main() {
  string a;
  int b;
  vector<int> A;
  cin >> a >> b;
  for (int i = a.size() - 1; i >=0 ; i--) A.push_back(a[i] - '0');
  int r = 0;
  auto res = div(A, b, r);
  for (int i = res.size() - 1; i >=0 ; i--) cout << res[i];
  cout << endl;
  cout << r << endl;

  return 0;
}
