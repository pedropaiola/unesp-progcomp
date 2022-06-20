#include <bits/stdc++.h>
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
typedef long long ll;
 
using namespace std;

vector<ll> v;
ll sum1 = 0, sum2 = 0;

vector<vector<vector<ll>>> dp;

ll brute(ll pos1, ll pos2, bool flag){
    if(pos1 > pos2){
        return 0;
    }
    if(dp[pos1][pos2][flag] != -1)return dp[pos1][pos2][flag];
    ll chamada1 = brute(pos1 + 1, pos2, !flag);
    ll chamada2 = brute(pos1, pos2 - 1, !flag);

    if(flag)return dp[pos1][pos2][flag] = max(v[pos1] + chamada1, v[pos2] + chamada2);
    return dp[pos1][pos2][flag] = min(chamada1, chamada2);
}
int main(){
    ll n; cin >> n;
    
    v = vector<ll>(n+1);
    dp = vector<vector<vector<ll>>> (n+1, vector<vector<ll>> (n+1, vector<ll> (2, -1)));

    ll soma = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        soma += v[i];
    }
    cout << 2*brute(0, n-1, 1) - soma << "\n";
   
}