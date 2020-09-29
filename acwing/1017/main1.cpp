// 题目：怪盗基德户滑翔翼
// f[i]: 以i结尾的最长上升子序列;
// f[i] = max(f[j]) + 1 for all (j < i and a[j] < a[i]);
// initial value: f[0] = 1;
// invalid value: f[i] = 0;

#include <iostream>
#include <algorithm>

using namespace std;

const int K = 110, N = 110, H = 100010;

int a[N]; // 建筑高度
int f[N];

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            cin >> a[i];
            for (int j = 0; j < i; j++)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        for (int i = n-1; i >= 0; i--) {
            f[i] = 1;
            for (int j = n-1; j > i; j--) 
                if (a[j] < a[i]) 
                    f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
    return 0;
}