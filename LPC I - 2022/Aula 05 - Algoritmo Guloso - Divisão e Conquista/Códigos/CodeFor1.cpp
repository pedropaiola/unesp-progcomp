#include<bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
ll valor(ll i, ll n, ll l, ll r){
    //cout << i << " " << n << " (" << l << " " << r << ")" << endl;
    if (n <= 1)
        return n;
    if (r - l == 0){
        return n/2;
    }
 
    ll meio = (l+r)/2;
    if (meio == i)
        return n % 2;
    
    ll l1 = l, r1 = meio - 1, l2 = meio + 1, r2 = r;
    if (i >= l1 && i <= r1)
        return valor(i, n/2, l1, r1);
    else
        return valor(i, n/2, l2, r2);    
}
 
int main(){
    ll n, l, r, i, lim, cont = 0;
    cin >> n >> l >> r;
    l--; r--;
    i = 1;
    int exp = 0;
    while(i <= n){
        i*= 2;
        exp++;
    }
    lim = (1LL << exp) - 1LL;
    for(i = l; i <= r; i++){
        cont += valor(i, n, 0, lim);
    }
    cout << cont << endl;
}