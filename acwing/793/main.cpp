#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> mul(vector<int> A, int b) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    C.push_back((A[i] * b + t) % 10);
    t = (A[i] * b + t) / 10;
  }
  while (t) C.push_back(t % 10), t /= 10;
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}

int main() {
  string a;
  int b;
  vector<int> A;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
  auto res = mul(A, b);
  for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
  cout << endl;
  
  return 0;
}
