#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    char f = 'G', s = 'B';
    if (a < b) {
        swap(a, b);
        swap(f, s);
    }

    int group_cnt = (a + k - 1) / k;
    if (b < group_cnt - 1) {
        cout << "NO";
        return;
    }

    for (int i = 0; i < group_cnt; i++) {
        int cntf = (i + 1 < group_cnt || a % k == 0 ? k : a % k);
        for (int j = 0; j < cntf; j++)
            cout << f;
        int cnts = min(k, b - max(0, (group_cnt - i - 2)));
        b -= cnts;
        for (int j = 0; j < cnts; j++)
            cout << s;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}