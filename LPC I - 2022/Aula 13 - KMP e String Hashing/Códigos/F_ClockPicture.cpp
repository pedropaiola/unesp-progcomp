//https://open.kattis.com/problems/clockpictures

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)


#define bint __int128
struct Hash {
    bint MOD = 212345678987654321LL,P=1777771,PI=106955741089659571LL;
    vector<bint> h,pi;
    Hash(vector<ll> s){
        assert((P*PI)%MOD==1);
        h.resize(s.size()+1);pi.resize(s.size()+1);
        h[0]=0;pi[0]=1;
        bint p=1;
        fore(i,1,s.size()+1){
            h[i]=(h[i-1]+p*s[i-1])%MOD;
            pi[i]=(pi[i-1]*PI)%MOD;
            p=(p*P)%MOD;
        }
    }
    ll get(int s, int e){
        return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
    }
};

int main()
{
    ll n;
    cin >> n;
    set<ll> s;
    
    vector<ll>dist;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        s.insert(x);
    }
   
    vector<ll>prim;
    for(auto x: s){
        prim.push_back(x);
    }
    ll tam = (prim.size());

    for(int i=0;i<tam;i++){
        ll a,b;
        a = prim[i];
        b = prim[(i+1)%tam];
    
        dist.push_back((b-a + 360000 )%360000);
    }

    s.clear();
    vector<ll>dist2;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        s.insert(x);
    }

    prim.clear();
    for(auto x: s){
        prim.push_back(x);
    }
    tam = (prim.size());

    for(int i=0;i<tam;i++){
        ll a,b;
        a = prim[i];
        b= prim[(i+1)%tam];
    
        dist2.push_back((b-a + 360000 )%360000);
    }
    tam = dist.size();
    for(int i=0;i<tam;i++){
        dist.push_back(dist[i]);
    }
    
    Hash hs(dist),ht(dist2);
    ll m = dist2.size();
    ll val = ht.get(0,m);
    bool flag = false;
    for(int i=0;i<ll(dist.size());i++){
        if(i+m-1>=ll(dist.size()))break;
        if(hs.get(i,i+m)==val){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "possible\n";
    }else{
        cout << "impossible\n";
    }

    return 0;
}