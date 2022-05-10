#include <bits/stdc++.h>

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;

using namespace std;
const ll mod = 1e9 + 7;

int main() {
    fast_io;
    ll n, x;
    cin >> n;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> x;
        mp[x]++;
    }
    ll ma = 0;
    for(auto u: mp){
        ma = max(u.second, ma);
    }
    cout << ma << " " << mp.size() << "\n";
    

}
