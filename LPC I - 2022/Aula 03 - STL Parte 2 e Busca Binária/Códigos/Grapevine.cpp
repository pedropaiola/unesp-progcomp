#include <bits/stdc++.h>

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;

using namespace std;
const ll mod = 1e9 + 7;


int main(){
    // fast_io;
    ll n, m;
    while(cin >> n >> m){
        if(n==0)break;
        ll u = max(n, m);
        vector<vector<ll>> v (n, vector<ll> (m));
        vector<vector<ll>> diag (2*u + 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
                diag[u + (i - j)].push_back(v[i][j]);
            }
        }
        ll xma = 0, yma = 0;
        ll a, b, q;
        cin >> q;
        ll tam;
        while(q--){
            cin >> a >> b;
            tam = 0;
            if(a > b)swap(a, b);
            for(int i = 0; i < n; i++){
                ll indd = lower_bound(v[i].begin(), v[i].end(), a) - v[i].begin();
                ll indu = upper_bound(v[i].begin(), v[i].end(), b) - v[i].begin();
                xma = indu - indd;
                indu--;
                if(indu >= 0)
                yma = upper_bound(diag[u + (i - indu)].begin(), diag[u + (i - indu)].end(), b) - lower_bound(diag[u + (i - indu)].begin(), diag[u + (i - indu)].end(), a);
                else yma = 0;
                tam = max(tam, min(xma, yma));
            }
            cout << tam << "\n";
        }
        cout << "-\n";
    }
    return 0;
}