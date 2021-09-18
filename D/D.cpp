#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int ans = 50;
string ans2;
string t;
int bal1 = 0, bal2 = 0;

void go(int pos, int val) {
    if (pos == n) {
        if (val < ans && bal1 == 0 && bal2 == 0) {
            ans = val;
            ans2 = t;
        }
        return;
    }
    t.push_back('(');
    bal1++;
    go(pos + 1, val + (s[pos] == '(' ? 0 : 1));
    bal1--;
    t.pop_back();

    if (bal1 > 0) {
        t.push_back(')');
        bal1--;
        go(pos + 1, val + (s[pos] == ')' ? 0 : 1));
        bal1++;
        t.pop_back();
    }

    t.push_back('[');
    bal2++;
    go(pos + 1, val + (s[pos] == '[' ? 0 : 1));
    bal2--;
    t.pop_back();

    if (bal2 > 0) {
        t.push_back(']');
        bal2--;
        go(pos + 1, val + (s[pos] == ']' ? 0 : 1));
        bal2++;
        t.pop_back();
    }
}


void solve() {
    cin >> n;
    cin >> s;

    go(0, 0);
    cout << ans << endl;
    cout << ans2;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}