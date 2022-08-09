//A - Number of Ways  - https://www.codechef.com/problems/NWAYS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxN=3e6;
const ll mod = 1e9 + 7;

ll Pow(ll a, ll b){
    ll r = 1LL;
    while(b){
        if(b&1) (r*=a) %= mod;
        b >>= 1;
        (a*=a) %= mod;
    }
    
    return r%mod;
}

int main()
{
    vector<ll>fac(maxN);
    vector<ll>i_fac(maxN);
    ll x = 1;
    ll val = 1;

    fac[0] = 1LL;
    i_fac[0] = Pow(fac[0], mod-2);
    //Precalculando, o fatorial e mod _inverso
    for(ll i = 1; i <= maxN; ++i){
        fac[i] = (fac[i-1]*i)%mod;
        i_fac[i] = Pow(fac[i], mod-2);
    }

    int t;
    cin >> t;
    int n, k;
    while (t--)
    {
        cin >> n >> k;
        // temp = (n+k+1, k+2)
        ll temp = ((fac[n+k+1]*i_fac[n-1])%mod*i_fac[k+2])%mod;
        //Acertando a saida de acordo com o mod
        cout << (2*temp-n+mod)%mod << '\n';
    }
}