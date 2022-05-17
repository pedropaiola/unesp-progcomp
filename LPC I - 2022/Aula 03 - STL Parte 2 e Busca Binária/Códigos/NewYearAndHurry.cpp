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
    ll n, k; cin >> n >> k;
    k = 240 - k;
    ll soma = 0, cont = 0;
    for(int i = 1; i <= n; i++){
        soma += i*5;
        if(soma <= k){
            cont++;
        }
    }
    cout << cont << "\n";
}