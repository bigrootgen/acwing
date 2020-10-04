// 题目： 货币系统
// 思路来源：完全背包 => 货币系统

// Input: 货币系统
// Output：最简等价货币系统

// 问题1：怎么判断一个货币系统最简？
// eg: 3, [2,5,9]
// 2x + 5y + 9z
// 结论1： 货币系统中最小面额不能被替代
// 结论2： 如果有a*k == b (a in [] and b in [])， 则b可以被删去
// 结论3： 如果有a*x + b*y == c （a in [], b in [], and c in [])， 则c可以被删去
// ... 如果(a1, a2, a3..) * (n1, n2, n3..) == c， 则c可以被删去

// 问题2： 如果c不能被前面的数表示，能该数能否被删去？
// 不能，如果不能被前面的数表示，且该数小于后面的数，则无法被表示

// 结论：我们将货币系统排序，从前到后枚举每一个数，如果该数能被前面的数表示，则可以删去此数，如果不能被前面的数表示，则该数不能被删去（那能被替换成其他数吗？）
// 不能，如果我们将c替换成x，那么x < c，否则我们无法表示c，则x > c, 则我们依然无法表示c

// 结论：我们将货币系统排序，从前到后枚举每一个数，如果该数能被前面的数表示，则删去此数，如果不能被前面的数表示，则保留此数

// 问题3：如果判读某一数能否被前面的数表示？
// ref： 货币系统

// f[i][j]: 从前i个数从选择，能表达j的方案数

#include <iostream>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 110, M = 25010;

int a[N];
int cnt;
bool f[M];

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        REP(i, n) cin >> a[i];
        sort(a, a+n);
        int m = a[n-1];
        // m表示a中最大的数
        cnt = 0;    
        memset(f, false, sizeof f);
        f[0] = true;
        REP(i, n) {
            if (!f[a[i]]) cnt++;
            for (int j = a[i]; j <= m; j++) {
                f[j] |= f[j-a[i]];
            }   
        }
        cout << cnt << endl;
    }
    return 0;
}