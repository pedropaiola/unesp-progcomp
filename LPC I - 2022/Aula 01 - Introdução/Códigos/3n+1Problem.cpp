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
    ll l, r;
    while(cin >> l >> r){
        ll cont = 0;
        ll ma = 0;
        cout << l << " " << r << " ";
        if(r < l){
            swap(r, l);
        }
        for(int i = l; i <= r; i++){
            cont = 1;
            ll n = i;
            while(n > 1){
                cont++;
                if(n&1) n = 3*n + 1;
                else n /=2;
            }
            ma = max(cont, ma);
        }
        cout << ma << "\n";
    }

}
