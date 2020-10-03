// 题目：买书
// 思路来源：完全背包问题

// f[i][j]: 从前i本书中选，不超过j的方案
// f[i][j] = f[i-1][j] + f[i-1][j-k*a[i]] 

#include <iostream>

using namespace std;

const int N = 1010;

int f[N];
int v[4] = {10, 20, 50, 100};

int main() {
    int n; cin >> n;
    f[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = v[i]; j <= n; j++) 
            f[j] += f[j - v[i]];
    cout << f[n] << endl;
    return 0;
}