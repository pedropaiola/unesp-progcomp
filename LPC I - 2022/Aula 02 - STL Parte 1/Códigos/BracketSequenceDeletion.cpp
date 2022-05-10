#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){
    fast_io
    ll t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll tam = s.size();

        ll cont = 0;
        int i = 0;
        ll res = tam;
        while(i <= tam-1){
            bool f = false;
            stack <char> st;
            char c = s[i];
            st.push(s[i]);
            for(int j = i+1; j < tam; j++){
                bool flag = false;
                if(s[j] == c){
                    int ini = i;
                    bool at = true; 
                    int fim = j;
                    while(ini <= fim){
                        if(s[ini++] != s[fim--]){
                            at = false;
                            break;
                        }
                    }
                    if(at == true)flag = true;

                }
                if(!st.empty()){
                    ll o = st.top();
                    if(o == '(' && s[j] == ')')st.pop();
                    else st.push(s[j]);
                }
                else st.push(s[j]);

                if(flag || st.empty()){
                    res -= (j - i + 1);
                    cont++;
                    i = j+1;
                    f = true;
                    break;
                }
                
            }
            if(!f)break; 
        }
        cout << cont << " " << res << "\n";

    }
    
}