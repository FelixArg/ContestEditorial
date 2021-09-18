#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    vector<pair<int, int>> pairs(m);

    for (int i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        cnt[pairs[i].first]++;
        cnt[pairs[i].second]++;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] >= m / 2) {
            vector<int> can;
            bool was = false;

            for (int j = 0; j < m; j++) {
                if (pairs[j].first == i || pairs[j].second == i)
                    continue;
                if (was == false) {
                    can.push_back(pairs[j].first);
                    can.push_back(pairs[j].second);
                    was = true;
                }
                else {
                    bool exist_first = false, exist_second = false;
                    for (int x : can) {
                        if (x == pairs[j].first)
                            exist_first = true;
                        if (x == pairs[j].second)
                            exist_second = true;
                    }
                    can.clear();
                    if (exist_first == true)
                        can.push_back(pairs[j].first);
                    if (exist_second == true)
                        can.push_back(pairs[j].second);
                }
            }

            if (was == false || can.empty() != true) {
                cout << "YES";
                return;
            }
        }
    }

    cout << "NO";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}