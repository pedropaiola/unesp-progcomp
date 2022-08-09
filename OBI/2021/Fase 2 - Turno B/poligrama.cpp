#include<bits/stdc++.h>

using namespace std;

int ps[26][100001];

vector<int> divisores(int n){
    vector<int> resp;
    resp.push_back(1);
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0){
            resp.push_back(i);
            resp.push_back(n/i);
        }
    }
    //Sem o próprio n, pois não vale para este problema
    sort(resp.begin(), resp.end());
    return resp;
}

bool verifica(int n, int d){
    int qtde[26];
    int i, j;

    //Contando a quantidade de cada letra nos primeiros d caracteres
    for(j = 0; j < 26; j++){
        qtde[j] = ps[j][d];
    }

    for(i = d; i + d <= n; i += d){
        for(j = 0; j < 26; j++){
            if (qtde[j] != (ps[j][i+d] - ps[j][i]))
                return false;
        }
    }
    return true;
}

int main(){
    string s;
    vector<int> divs;
    int n;
    
    cin >> n;
    cin >> s;
    
    memset(ps, 0, sizeof(ps));
    for(int j = 0; j < 26; j++){
        ps[j][0] = 0;
        for(int i = 0; i < n; i++){
            ps[j][i+1] = ps[j][i] + (s[i] == ('a' + j));
        }
    }

    divs = divisores(s.size());
    bool ok = false;
    for(auto d : divs){
        if (verifica(n, d)){
            ok = true;
            cout << s.substr(0, d) << "\n";
            break;
        }
    }
    if (!ok)
        cout << "*\n";
}