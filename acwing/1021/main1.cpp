// 题目：货币系统
// 思路来源：完全背包

// f[i][j]: 从前i中面值中选，面值和为j的选法
// f[i][j] = f[i-1][j] + f[i-1][j-k*v[i]] for k st j >= k*v[i];

// invalid value: f[i][j] = 0;
// initial value: f[0][0] = 1;

#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)

typedef long long LL;

using namespace std;

const int N = 20, M = 3010;

LL f[M];

int main() {
    int n, m; cin >> n >> m;
    f[0] = 1;
    REP(i, n) {
        int a; cin >> a;
        for (int j = a; j <= m; j++) f[j] = f[j] + f[j-a];
    }
    cout << f[m] << endl;
    return 0;
}