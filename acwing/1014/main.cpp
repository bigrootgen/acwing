// 题目： 登山
// 思路来源： 最长上升子序列

#include <iostream>

using namespace std;

const int N = 1010;

int a[N];
int f1[N]; // 上升序列
int f2[N]; // 下降序列

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f1[i] = 1;
        cin >> a[i];
        for (int j = 0; j < i; j++) if (a[j] < a[i]) f1[i] = max(f1[i], f1[j] + 1);
    }
    for (int i = n-1; i >= 0; i--) {
        f2[i] = 1;
        for (int j = n-1; j > i; j--) if (a[j] < a[i]) f2[i] = max(f2[i], f2[j] + 1);
    }
    for (int i = 0; i < n; i++) ans = max(ans, f1[i] + f2[i]);
    cout << ans-1 << endl;
    return 0;
}