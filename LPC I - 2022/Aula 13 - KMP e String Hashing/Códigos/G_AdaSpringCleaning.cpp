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
	Hash(string& s){
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
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        Hash hs(s);
        map<ll,bool>mp;

        for(int i=0;i<n;i++){
            if(i+k-1>=n)break;
                mp[hs.get(i,i+k)]=true;
        }
       
        cout << int(mp.size()) << "\n";

    }

    return 0;
}