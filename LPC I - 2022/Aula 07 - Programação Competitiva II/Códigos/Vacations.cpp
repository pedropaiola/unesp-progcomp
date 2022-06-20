#include <bits/stdc++.h>
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
typedef long long ll;
 
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    vector<vector<ll>> dp (n+1, vector<ll> (2, 0));
    
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            ll aux = min(dp[i-1][0], dp[i-1][1]) + 1;
            dp[i][0] = aux;
            dp[i][1] = aux;
        }
        else if(v[i] == 1){
            dp[i][1] = min(dp[i-1][0], dp[i-1][1] + 1);
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + 1;
        }
        else if(v[i] == 2){
            dp[i][0] = min(dp[i-1][1], dp[i-1][0] + 1);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
        }
        else {
            dp[i][0] = min(dp[i-1][1], dp[i-1][0] + 1);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1] + 1);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
}