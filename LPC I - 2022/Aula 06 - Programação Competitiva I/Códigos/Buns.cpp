#include <bits/stdc++.h>
using namespace std;
#define fast_io  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<tuple<ll, ll, ll, ll>> v;

ll n, m, d0, c0;

vector<vector<ll>> dp;

ll brute(ll pos, ll val){
    ll qnt;
    if(pos == m){
        qnt = val/c0;
        return qnt*d0;
    }
    if(dp[pos][val] != -1)return dp[pos][val];
    ll res = 0;
    ll a, b, c, d;

    a = get<0>(v[pos]);
    b = get<1>(v[pos]);
    c = get<2>(v[pos]);
    d = get<3>(v[pos]);

    ll usos = 0;
    for(; usos*c <= val && usos*b <= a; usos++){
        res = max(res, usos*d + brute(pos+1, val -  usos*c));
    }

    return dp[pos][val] = res;
}

int main(){
    cin >> n >> m >> c0 >> d0;
    dp = vector<vector<ll>> (m, vector<ll> (n+1, -1));
    for(int i = 0; i < m; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }
    cout << brute(0, n) << "\n";
}