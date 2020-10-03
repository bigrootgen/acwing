// 题目： 导弹防御系统
// 思路来源：拦截导弹，DFS，贪心，优先队列

// DFS:
// 搜索顺序：
// 对每一个导弹，我们考虑放入已有的防御系统，或者开一个新的防御系统
// 问题1：在能放的情况下，是否优先放入已有的防御系统? 答案：是的，证明略

// 状态表示： 
// dfs(int t, int su, int sd); // 参数传递状态
// int up[N], down[N]; // 全局变量传递状态，需要恢复现场
// 由两个优先队列和当前的导弹序号构成

// 边界： if (u == n) {ans = min(ans, su+sd); return:}
// 最优化减枝: if (su + sd >= ans) return;

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int h[N];
int up[N], down[N];
int ans;

void dfs(int u, int su, int sd)
{
    if (su + sd >= ans) return;
    if (u == n)
    {
        ans = min(ans, su + sd);
        return;
    }

    int k = 0;
    while (k < su && up[k] >= h[u]) k ++ ;
    if (k < su)
    {
        int t = up[k];
        up[k] = h[u];
        dfs(u + 1, su, sd);
        up[k] = t;
    }
    else
    {
        up[k] = h[u];
        dfs(u + 1, su + 1, sd);
    }

    k = 0;
    while (k < sd && down[k] <= h[u]) k ++ ;
    if (k < sd)
    {
        int t = down[k];
        down[k] = h[u];
        dfs(u + 1, su, sd);
        down[k] = t;
    }
    else
    {
        down[k] = h[u];
        dfs(u + 1, su, sd + 1);
    }
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i ++ ) cin >> h[i];

        ans = n;
        dfs(0, 0, 0);

        cout << ans << endl;
    }

    return 0;
}
