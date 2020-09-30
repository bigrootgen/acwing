// 题目：最长公共子序列
// 思路来源：动态规划
// f[i][j]: s1[0-i-1]与s2[0-j-1]的最长公共子序列
// f[i][j] = max(f[i-1][j], f[i][j-1]) if s1[i] != s2[j];
// f[i][j] = f[i-1][j-1] + 1 if s1[i] == s2[j] 
// invalid value f[i][j] = 0;
// initial value f[i][j] = 1;

#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

const int N = 1010;

char s1[N], s2[N];
int f[N][N];

int main() {
    int n, m; cin >> n >> m;
    cin >> s1 >> s2;
    REP(i, n) REP(j, m) {
        f[i][j] = max(f[i-1][j], f[i][j-1]);
        if (s1[i] == s2[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
    }
    cout << f[n-1][m-1] << endl;
}
