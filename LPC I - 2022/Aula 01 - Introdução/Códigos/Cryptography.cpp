#include <bits/stdc++.h>
 
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
typedef long long ll;
using namespace std;


int main(){
    vector<ll> primos;
    ll n = 1000000;
    vector<bool> ehPrimo(n+1, true);
    ehPrimo[1] = false;
    ehPrimo[0] = false;

    for(int i = 2; i*i < n; i++){
        if(ehPrimo[i]){
            for(int j = i*i; j < n; j+=i){
                ehPrimo[j] = false;
            }
        }
    }
    for(int i = 2; i < n; i++){
        if(ehPrimo[i])primos.push_back(i);
    }
    // cout << primos.size() << "\n";
    fast_io;
    ll t; cin >> t;
    while(t--){
        ll a; cin >> a;
        cout << primos[a-1] << "\n";
    }
    return 0;
}