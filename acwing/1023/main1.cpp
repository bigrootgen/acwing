// 题目： 买书
// 思路来源： 完全背包 => 货币系统

#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 1010;

int v[4] = {10, 20, 50, 100};
int f[N];

int main() {
    int m; cin >> m;
    f[0] = 1;
    REP(i, 4) for (int j = v[i]; j <= m; j++) f[j] = f[j] + f[j-v[i]];
    cout << f[m] << endl;
    return 0;
}