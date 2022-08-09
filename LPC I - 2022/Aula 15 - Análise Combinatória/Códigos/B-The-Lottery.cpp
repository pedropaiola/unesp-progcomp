#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
    if(a == 0)return b;
    return gcd(b%a, a);
}
ll fmmc(ll a, ll b){
    if(a < b)swap(a, b);
    return (a/gcd(a, b)) * b;
}
ll brute(vector<ll> &a, ll usou, ll pos, ll mmc, ll n){
    if(pos == a.size()){
        ll cont = 0;
        for(int i = 0; i < 15; i++) if((1LL << i) & usou)cont++;
        if(cont & 1) return -n/mmc;
        return n/mmc;
    }
    ll res = 0;
    res += brute(a, (1LL << pos) | usou, pos+1, fmmc(mmc, a[pos]), n);
    res += brute(a, usou, pos+1, mmc, n);
    return res;
}
int main(){
    ll n, k;
    while (cin >> n >> k){
        ll a;
        vector<ll> conjunto;
        ll soma = 0;
        for(int i = 1; i <= k; i++){
            cin >> a;
            conjunto.push_back(a);
            soma += n/a;
        }
        cout << brute(conjunto, 0, 0, 1, n) << "\n";

    }
}