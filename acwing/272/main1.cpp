// 题目：LCIS
// 思路来源：LIS, LCS

// 状态表示:
// f[i][j]: 所有以b[j]结的的a[1-i]与b[1-j]的公共上升子序列构成的集合

// 微分:
// f[i][j] - f[i-1][j] - f[i][j-1]: 所有以a[i]和b[j]结尾的公共上升子序列的集合， 这个集合可能对f[i][j]有contribution

// f[i][j] = max(f[i-1][j], f[i][j-1]) if a[i] != b[j]
// else max(f[i-1][j], f[i][j-1], 在a[1-i-1]与b[1-j-1]中最大值小于b[j]的公共上升子序列 + 1) 

// contribution set: 
// 哪个集合使得我们的维度扩张时对应的当前状态的结果增大(for max)或者减小(for min)?

// 上述微分集合(contribution set) == 在a[1-i]与b[1-j]中以b[j]结尾的的公共上升子序列
// 我们定义f[i][j]为上述集合，重新进行状态表示，微分过程

// 积分:
// f[i][j] = f[i-1][j] if a[i] != b[j]
// else max(f[i-1][j], f[i-1][k] + 1) for 0 <= k < j and b[k] < b[j]

// 非法状态和初始状态:
// invalid value: f[i][j] = 0
// initial value: f[i][j] = 0

// remark: 为什么k从0开始？
// new concept: contribution
// 有时invalid状态到normal状态具有contribution， 例如此题和LCS
// 有时invalid状态到normal状态没有contribution, 例如LIS

// 优化:
// for (int i = 1; i <= n; i++)
//  int maxv = 1;
//  for (int j = 1; j <= n; j++)
//          f[i][j] = f[i-1][j];
//          if (a[i] == b[j]) f[i][j] = maxv(f[i][j], maxv);
//          if (b[j] < a[i]) maxv = max(maxv, f[i-1][j] + 1);
// 

#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 1; i <= n; i++)

const int N = 3010;

int a[N], b[N];
int f[N][N];

int main() {
    int n; cin >> n;
    int res = 0;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    REP(i, n) {
        int maxv = 1;
        REP(j, n) {
            f[i][j] = f[i-1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if (b[j] < a[i]) maxv = max(maxv, f[i-1][j] + 1);
            res = max(res, f[i][j]);
        }
    }
    cout << res << endl;
    return 0;   
}