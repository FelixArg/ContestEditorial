#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> inv_p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        inv_p[p[i]] = i;
    }

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        if (p[i] != 0 && inv_p[p[i] - 1] < i)
            dp[i] = dp[inv_p[p[i] - 1]] + 1;
    }

    int ans = n;

    for (int i = 0; i < n; i++) {
        ans = min(ans, n - dp[i]);
    }

    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}