#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll x, k;
    cin >> x >> k;

    ll ans = 0;
    while (x != 1 && k != 0) {
        x++;
        while (x % 3 == 0) {
            x /= 3;
            ans++;
        }
        k--;
    }
    ans += k / 2;

    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}