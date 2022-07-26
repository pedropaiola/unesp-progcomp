#include<bits/stdc++.h>
#define ll long long int

using namespace std;

/* String Hash + Backward Hashing */
//Além do String Hash normal, também calcula a função String Hash com a string reversa. Útil para brincar com palíndromos
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const ll P = 1e18+9;
const ll b = uniform_int_distribution<ll>(0, P-1)(rng);

inline ll mult(ll a, ll b, ll mod){
    return (a*b-(ll)((long double)a/mod*b)*mod + mod)%mod;
}

struct hash_str
{
    vector<ll> h, hb, p;

    hash_str(string s) : h(s.size()), hb(s.size()), p(s.size()) {
        int n = s.size();
        h[0] = s[0] + 128;
        hb[0] = s[n-1] + 128;
        p[0] = 1;
        for(int i = 1; i < n; i++){
            h[i] = (mult(h[i-1],b,P) + s[i] + 128) % P;
            hb[i] = (mult(hb[i-1],b,P) + s[n-i-1] + 128) % P;
            p[i] = mult(p[i-1],b,P);
        }
    }

    ll sub_hash(int l, int r){
        if (l == 0)
            return h[r];
        ll ans = (h[r] - mult(h[l-1], p[r-l+1],P)) % P;
        if (ans < 0)
            ans += P;
        return ans;
    }

    ll sub_hash_backward(int l, int r){
        if (l == 0)
            return hb[r];
        ll ans = (hb[r] - mult(hb[l-1], p[r-l+1],P)) % P;
        if (ans < 0)
            ans += P;
        return ans;
    }
};

int main(){
    int t;
    string s, p;
    cin >> t;
    while(t--){
        cin >> s >> p;
        hash_str hs(s), hp(p);

        int ans = 0;
        vector<int> pos;

        int n = s.size(), m = p.size();
        for(int i = 0; i < n-m+1; i++){
            if (hs.sub_hash(i, i+m-1) == hp.sub_hash(0, m-1)){
                ans++;
                pos.push_back(i+1);
            }
        }
        if (ans == 0)
            cout << "Not Found\n\n";
        else
        {
            cout << ans << endl;
            for(auto i : pos)
                cout << i << " ";
            cout << "\n\n";
        }
    }
}