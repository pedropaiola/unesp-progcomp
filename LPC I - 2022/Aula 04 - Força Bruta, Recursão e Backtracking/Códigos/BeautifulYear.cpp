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
    string s;
    for(int i = n+1; i <= 10000; i++){
        map <ll, ll> mp;
        ll aux = i;
        bool flag = true;
        while(aux > 0){
            if(mp[aux%10]){
                flag = false;
                break;
            }
            mp[aux%10]++;
            aux/=10;
        }
        if(flag){
            cout << i << "\n";
            return 0;
        }
    }
}