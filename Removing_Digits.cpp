#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

unordered_map<ll, ll> dp;

ll func(ll val) {
    if (val == 0) {
        return 0;
    }
    if (dp.find(val) != dp.end()) {
        return dp[val];
    }
    string s = to_string(val);
    ll mini = 1e9; 
    for (char c : s) {
        ll digit = c - '0';
        if (digit > 0) {
            ll nval = val - digit;
            mini = min(mini%mod, (1 + func(nval))%mod);
        }
    }
    dp[val] = mini%mod;
    return mini%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = func(n);
    cout << ans << endl;
    return 0;
}
