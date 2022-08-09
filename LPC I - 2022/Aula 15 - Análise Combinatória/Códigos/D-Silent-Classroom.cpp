#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    map<char, ll> mp;
    while(t--){
        string s; cin >> s;
        mp[s[0]]++;
    }
    ll cont = 0;
    for(auto x: mp){
        ll n = (x.second+1)/2;
        ll m = x.second/2;
        cont += (n*(n-1))/2;
        cont += (m*(m-1))/2;
    }
    cout << cont << "\n";
    return 0;
}