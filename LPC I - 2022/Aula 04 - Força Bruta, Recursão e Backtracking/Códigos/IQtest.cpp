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
    vector<ll> v(n);
    ll zeros = 0, uns = 0;
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
        v[i] %= 2;
        if(v[i])uns++;
        else zeros++;
    }

    for(int i = 0 ; i < n; i++){
        if(uns > zeros && !v[i]){
            cout << i+1 << "\n";
            return 0;
        }
        else if(zeros > uns && v[i]){
            cout << i+1 << "\n";
            return 0;
        }
    }
    
    return 0; 
}