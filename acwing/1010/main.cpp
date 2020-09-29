// 题目： 拦截导弹
// 思路来源： LIS, 贪心, 单调队列

#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

const int N = 1010;

int a[N];
int f[N];
int q[N], hh, tt = -1;

int main() {
    int n = 0;
    int ans = 0;
    while (cin >> a[n]) n++;
    REP(i, n) {
        f[i] = 1;
        REP(j, i) if (a[i] <= a[j]) f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
        int k = hh; 
        while (k <= tt && q[k] < a[i]) k++;
        if (k <= tt) q[k] = a[i];
        else q[++tt] = a[i];
    }
    cout << ans << endl;
    cout << tt - hh + 1 << endl;
    return 0;
}