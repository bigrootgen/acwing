// 题目： 合唱队形
// 思路来源： 1014 登山

#include <iostream>

using namespace std;

const int N = 110;

int a[N];
int f1[N], f2[N];

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        f1[i] = 1;
        for (int j = 0; j < i; j++) if (a[j] < a[i]) f1[i] = max(f1[i], f1[j] + 1);
    }
    for (int i = n-1; i >= 0; i--) {
        f2[i] = 1;
        for (int j = n-1; j > i; j--) if (a[j] < a[i]) f2[i] = max(f2[i], f2[j] + 1);
    }
    for (int i = 0; i < n; i++) ans = max(ans, f1[i] + f2[i] - 1);
    cout << n - ans << endl;
    return 0;
}