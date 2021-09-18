#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'C') {
                r[i]++;
                c[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += r[i] * (r[i] - 1) / 2;
        ans += c[i] * (c[i] - 1) / 2;
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