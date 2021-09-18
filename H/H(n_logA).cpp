#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> vars;

    int t = a[0];
    while (t > 0) {
        vars.push_back(t);
        t /= k;
    }
    vars.push_back(0);

    reverse(vars.begin(), vars.end());
    vector<int> cnt(n);
    vector<int> pref(n + 1);

    for (int i = 0; i < n; i++) {
        int t = a[i];
        while (true) {
            while (t < vars.back()) {
                vars.pop_back();
                pref[0]++;
                pref[i + 1]--;
            }
            if (t == vars.back())
                break;
            t /= k;
            cnt[i]++;
        }
    }

    vector<int> dist(32);

    for (int i = 1; i < n + 1; i++) {
        pref[i] += pref[i - 1];
        cnt[i - 1] += pref[i];
        dist[cnt[i - 1]]++;
    }

    vector<int> ans;

    while (vars.back() != 0) {

        vector<int> temp_dist = dist;
        bool ok = 1;

        for (int i = 31; i > 0; i--) {
            int cnt_all = (dist[i] / k) * k;
            dist[i] -= cnt_all;
            if (i != 0)
                dist[i - 1] += cnt_all;
            if (dist[i] > 0) {
                int j = i;
                int to_full = 0;
                int pred_add = 0;

                for (int j = i; j > 0; j--) {
                    if (to_full + dist[j] >= k) {
                        dist[j - 1] += k - to_full;
                        dist[j] -= k - to_full;
                        dist[j] += pred_add;
                        to_full = k;
                        break;
                    }
                    else {
                        to_full += dist[j];
                        int cur = dist[j];
                        dist[j] += pred_add;
                        pred_add = cur;
                    }
                }

                if (to_full < k)
                    ok = 0;
            }
        }

        if (dist[0] != n)
            ok = 0;

        if (ok)
            ans.push_back(vars.back());

        dist.swap(temp_dist);

        vars.pop_back();
        for (int i = 30; i >= 0; i--) {
            dist[i + 1] = dist[i];
            dist[i] = 0;
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << ' ';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}