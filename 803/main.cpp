#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

int main() {
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    segs.push_back({l, r});
  }
  sort(segs.begin(), segs.end());

  int cnt = 1;
  int l = segs[0].first, r = segs[0].second;
  for (int i = 1; i < segs.size(); i++) {
    if (segs[i].first > r) l = segs[i].first, cnt ++;
    if (segs[i].second > r) r = segs[i].second;
  }

  cout << cnt << endl;

  return 0;
}
