#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(ll sum, vector<int>& a, vector<ll>& dp) {
    if (sum == 0) {
        return 0;
    }
    if (dp[sum] != -1) {
        return dp[sum];
    }
    ll res = 1e9;
    for (int i = 0; i < a.size(); i++) {
        if (sum - a[i] >= 0) {
            res = min(res, 1 + func(sum - a[i], a, dp));
        }
    }
    return dp[sum] = res % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& it : a) {
        cin >> it;
    }
    vector<ll> dp(m + 1, -1);
    ll ans = func(m, a, dp);
    if (ans >= 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
