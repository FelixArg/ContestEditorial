#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    multiset<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    vector<int> ans;

    while (*(--st.end()) != 0) {
        if (*st.begin() == *(--st.end()))
            ans.push_back(*st.begin());
        vector<int> ins;
        for (int i = 0; i < k; i++) {
            int v = *(--st.end());
            st.erase(--st.end());
            ins.push_back(v / k);
        }
        for (int x : ins)
            st.insert(x);
    }

    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << ' ';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}