#include <bits/stdc++.h>
 
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
typedef long long ll;
 
using namespace std;
const ll mod = 1e9 + 7;

bool flag;

int main(){
    fast_io;
    ll a, b, n;
    while(cin >> a >> b >> n){
        flag = false;
        ll ca = 0, cb = 0;
        while(ca != n && cb != n){
            if(ca == 0){
                cout << "fill A\n";
                ca = a;
            }
            else if(cb == b){
                cout << "empty B\n";
                cb = 0;
            }
            else{
                ll val = min(b-cb, ca); 
                ca -= val;
                cb += val;
                cout << "pour A B\n";
            }
        }
        cout << "success\n";
    }
    return 0; 
}