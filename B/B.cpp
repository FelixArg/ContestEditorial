#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    ll min_value = (1ll << 61); // 2^61
    ll max_value = -(1ll << 61); // -2^61

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        min_value = min(min_value, x);
        max_value = max(max_value, x);
    }

    if (min_value >= -128 && max_value <= 127)
        cout << "byte";
    else if (min_value >= -32768 && max_value <= 32767)
        cout << "short";
    else if (min_value >= -2147483648 && max_value <= 2147483647)
        cout << "int";
    else
        cout << "long";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}