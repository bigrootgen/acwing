// 题目： 最大上升子序列和
// 思路来源: LIS
// 状态表示：f[i]: 在a[0]-a[i]中的上升子序列的和
// 属性: max
// 转移方程:f[i] = max(f[j]) + a[i] for j < i and a[j] < a[i]
// initial value: f[i] = a[i];
// invalid value: f[i] = 0 本题不会访问到invalid value

#include <iostream>

using namespace std;

const int N = 1010;

int a[N];
int f[N];

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i], f[i] = a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) if (a[i] > a[j]) f[i] = max(f[i], f[j] + a[i]);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}