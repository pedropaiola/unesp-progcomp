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
    ll t; cin >> t;
    while(t--){
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<ll> v(m);
 
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }
        sort(begin(v), end(v));
 
        ll tempo = abs(a-b);
        vector<ll> res;
        ll cont = 0;
        ll tempof = tempo;
 
        if(a < b) tempof += a-1;
        else tempof += n-a;
 
        for(int i = m-1; i >= 0; i--){
            if(cont == tempo-1)break;
            if(v[i] + cont + 1 <= tempof){
                res.push_back(v[i]);
                cont++;
            }
        }
        cout << res.size() << "\n";
    }
}