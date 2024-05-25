#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(ll sum,vector<ll> &a,vector<ll> &dp){
    if(sum==0){
        return 1;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    ll pick = 0;
    for(int i=0;i<a.size();i++){
        if(sum-a[i]>=0){
            pick += func(sum-a[i],a,dp)%mod;
        }
    }
    return dp[sum] = pick%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n,0);
    for(auto &it: a){
        cin >> it;
    }
    vector<ll> dp(x+1,-1);
    ll ans = func(x,a,dp);
    cout << ans << endl;

    return 0;
}