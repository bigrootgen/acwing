// 题目：二维费用的背包问题
// 思路来源：01背包问题

#include <iostream>

using namespace std;

const int N = 110;

int f[N][N];

int main() {
    int n, v, m; cin >> n >> v >> m;
    for (int i = 0; i < n; i++) {
        int a, b, s; cin >> b >> s >> a;
        for (int j = v; j >= b; j--)
            for (int k = m; k >= s; k--) 
                f[j][k] = max(f[j][k], f[j-b][k-s] + a);
    }
    cout << f[v][m] << endl;
    return 0;
}