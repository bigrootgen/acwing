// 题目：数字组合
// 思路来源：01背包问题

// f[i][j]: 从前i个数字中选，和为j
// f[i][j] = f[i-1][j] + f[i-1][j-a[i]] 

// invalid value: f[i][j] = 0;
// initial value: f[0][0] = 1;

#include <iostream>

using namespace std;

const int N = 110, M = 10010;

int f[M];

int main() {
    int n, m; cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = m; j >= a; j--) 
            f[j] = f[j] + f[j-a];
    }
    cout << f[m] << endl;
    return 0;
}