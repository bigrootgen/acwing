#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int N = 1000010;

int q[N], a[N];

int main() {
    int n, k; cin >> n >> k;
    int hh = 0, tt = -1;
    REP(i, n) cin >> a[i];
    REP(i, n) {
        if (tt >= hh && q[tt] - q[hh] + 1 > k) hh++;
        while (tt >= hh && a[i] <= a[q[tt]]) tt--;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }
    cout << endl;
    hh = 0, tt = -1;
    REP(i, n) {
        if (tt >= hh && q[tt] - q[hh] + 1 > k) hh++;
        while (tt >= hh && a[i] >= a[q[tt]]) tt--;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }
    cout << endl;
    return 0;
}