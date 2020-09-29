// 题目： 友好城市
// 思路来源： LIS

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

PII a[N];
int f[N];

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) if (a[i].second > a[j].second) f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }   
    cout << ans << endl;
    return 0;
}

