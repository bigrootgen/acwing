#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> A, vector<int> B) {
  vector<int> C;
  int i = 0;
  int c = 0;
  while (i < A.size() || i < B.size()) {
    if (i < A.size()) c += A[i];
    if (i < B.size()) c += B[i];
    C.push_back(c % 10);
    c = c / 10;
    i++;
  }
  if (c) C.push_back(c);
  return C;
}

int main() {
  string a, b;
  vector<int> A, B;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

  auto C = add(A, B);
  for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
  cout << endl;

  return 0;
}


