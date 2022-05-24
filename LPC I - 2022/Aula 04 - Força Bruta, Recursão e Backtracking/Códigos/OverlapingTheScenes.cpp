#include <bits/stdc++.h>
 
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
typedef long long ll;
 
using namespace std;
const ll mod = 1e9 + 7;

string res;

ll brute(vector<string> &v, int cont, ll n, vector<bool> &vis){
    if(cont == n){
        return res.size();
    }
    ll ans = 1e17;

    for(int i = 0; i < n; i++){
        if(vis[i])continue;
        ll p, j;
        string aux = res;
        bool flag = false;
        
        for(int k = 0; k < res.size(); k++){
            p = k;
            j = 0;
            while(p < res.size() && j < v[i].size() && res[p] == v[i][j]){
                j++;
                p++;
            }
            if(p == res.size()){
                res += v[i].substr(j);
                flag = true;
                break;
            }
        }

        if(!flag) res += v[i];
        vis[i] = true;

        ans = min(ans, brute(v, cont+1, n, vis));

        vis[i] = false;
        res = aux;
    }    
    return ans;
}

int main(){
    fast_io;
    ll t; cin >> t;

    for(int x = 1; x <= t; x++){
        ll n;
        vector<string> v;
        cin >> n;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        cout << "Case " << x << ": " << brute(v, 0, n, vis) << "\n";
    }
    return 0; 
}