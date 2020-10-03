// 题目：装箱问题
// 思路来源：背包问题

// 形成了与01背包问的的同构
// 收益和代价都是物品的体积，在一定代价内求最大收益

#include <iostream>

using namespace std;

const int V = 200010, N = 40;

int f[V];

int main() {
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = m; j >= a; j--) f[j] = max(f[j], f[j-a] + a);
    }
    cout << m-f[m] << endl;
    return 0;
}