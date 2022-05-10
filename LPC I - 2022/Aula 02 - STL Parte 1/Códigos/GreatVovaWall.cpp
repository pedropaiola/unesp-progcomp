#include <bits/stdc++.h>

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;

using namespace std;
const ll mod = 1e9 + 7;


int main(){
    fast_io;
    ll n; cin >> n;
    stack <ll> p;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(!p.empty() && (p.top() & 1) == (x & 1)){
            while(!p.empty() && (p.top() & 1) == (x & 1)){
                p.pop();
            }
        }
        else p.push(x);
    }
    if(p.size() <= 1)cout << "YES\n";
    else cout << "NO\n";
}