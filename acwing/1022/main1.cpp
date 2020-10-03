// 题目：宠物小精灵之收服
// 思路来源：双重代价的背包问题

// 代价1：精灵球个数
// 代价2：皮卡丘体力
// 收益：收服精灵数

// f[i][j][k]: 前[1-i]个精灵中选择，且当前精灵球数量为j，皮卡丘体力为k;
// f[i][j][k] = max(f[i-1][j][k], f[i-1][j-a][k-b] + 1) for j >= a and k > b;

// invalid value: f[i][j][k] = 0;
// initial value: f[i][j][k] = 0;

#include <iostream>

using namespace std;

const int N = 1010, M = 510, K = 110;

int f[N][M];

int main() {
    int n, m, x; cin >> m >> x >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int j = m; j >= a; j--) 
            for (int k = x; k > b; k--) 
                f[j][k] = max(f[j][k], f[j-a][k-b] + 1);
    }
    cout << f[m][x] << " ";
    int i = 1; 
    while (f[m][i] != f[m][x]) i++;
    cout << x-i+1 << endl;
}