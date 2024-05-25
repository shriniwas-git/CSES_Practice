// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// ll func(ll ind,ll sum,vector<ll> &a,vector<vector<ll>> &dp){
//     if(sum==0){
//         return 1;
//     }
//     if(ind<0){
//         return 0;
//     }
//     if(dp[ind][sum]!=-1){
//         return dp[ind][sum];
//     }
//     ll pick = 0,npick = 0;
//     if(sum>=a[ind]){
//         pick = func(ind,sum-a[ind],a,dp)%mod;
//     }
//     npick = func(ind-1,sum,a,dp)%mod;
//     return dp[ind][sum] = (pick+npick)%mod;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll n,x;
//     cin >> n >> x;
//     vector<ll> a(n,0);
//     for(auto &it: a){
//         cin >> it;
//     }
//     vector<vector<ll>> dp(n,vector<ll> (x+1,-1));
//     ll ans = func(n-1,x,a,dp);
//     cout << ans << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &it : a) {
        cin >> it;
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;  // There's one way to make the sum 0, by choosing nothing.

    for (ll i = 0; i < n; ++i) {
        for (ll j = a[i]; j <= x; ++j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
