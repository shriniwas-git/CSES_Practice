#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(ll sum,vector<ll> &dp){
    if(sum==0){
        return 1;
    }
    ll ways = 0;
    if(dp[sum]!=-1){
        return dp[sum];
    }
    for(ll i=1;i<=6;i++){
        if(sum>=i){
        ways += func(sum-i,dp)%mod;
        }
    }
    return dp[sum] = ways%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> dp(n+1,-1);
    ll ans = func(n,dp);
    cout << ans << endl;
    return 0;
}