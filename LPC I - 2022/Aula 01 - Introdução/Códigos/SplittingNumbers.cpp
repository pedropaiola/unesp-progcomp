#include <bits/stdc++.h>
 
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
typedef long long ll;
using namespace std;

int main(){
    fast_io;
    ll n;
    while(cin >> n){
        if(n == 0)break;
        ll a = 0, b = 0;
        ll cont = 0;
        for(int i = 0; i < 31; i++){
           if((1 << i) & n){
               if(cont & 1){
                   b |= 1 << i;
               }
               else{
                   a |= 1 << i;
               }
               cont++;
           } 
        }
        cout <<  a << " " << b << "\n";
    }
    return 0;
}