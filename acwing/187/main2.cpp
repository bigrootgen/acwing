#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++) 

const int N = 60;

int a[N];
int up[N], down[N];
int n, ans;

void dfs(int u, int su, int sd) {
    if (u == n) {
        ans = min(ans, su+sd);
        return;
    }
    if (su + sd >= ans) return;

    int k = 0;
    while (k < su && a[u] <= up[k]) k++; // find the first up[k] > a[u];
    if (k < su) {
        int t = up[k];
        up[k] = a[u];
        dfs(u+1, su, sd);
        up[k] = t;
    }
    else {
        up[su] = a[u];
        dfs(u+1, su+1, sd);
    }

    k = 0;
    while (k < sd && a[u] >= down[k]) k++;
    if (k < sd) {
        int t = down[k];
        down[k] = a[u];
        dfs(u+1, su, sd);
        down[k] = t;
    }
    else {
        down[sd] = a[u];
        dfs(u+1, su, sd+1);
    }
}

int main() {
    while (cin >> n, n) {
        REP(i, n) cin >> a[i]; 
        ans = n;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}