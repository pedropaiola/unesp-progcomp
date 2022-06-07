#include <bits/stdc++.h>
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
typedef long long ll;
 
using namespace std;
const ll mod = 1e9 + 7;

ll t, k;
ll dp[100005];
ll func(ll i){
    if(i < 0)return 0;
    if(dp[i] != -1)return dp[i];
    if(i == 0) return dp[i] = 1;
    ll res = 0;
    res += func(i-k);
    res %= mod;
    res += func(i-1);
    res %= mod;
    return dp[i] = res;
}
int main(){
    fast_io;
    memset(dp, -1, sizeof dp);
    cin >> t >> k;
    func(100000);
    vector<ll> pre (100001);
    pre[0] = 0;
    for(int i = 1; i <= 100000; i++){
        pre[i] = dp[i] + pre[i-1];
    }
    while(t--){
        ll a, b; cin >> a >> b;
        cout << (pre[b] - pre[a-1] + mod) % mod << "\n";
    }
}