#include<bits/stdc++.h>

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

//Quantos movimentos são necessários para transformar a 
//string s em uma string só com caracteres c
int onlyc(string s, char c){
    int qtdeMov = 0;
    for(auto x : s){
        qtdeMov += (c != x);
    }
    return qtdeMov;
}

//quantos movimentos são necessários para transformar a
//string s em uma c-good string
int goodStr(string s, char c){
    if (c > 'z') //Solução inválida (nem vai chegar acontecer isso, pelo enunciado do problema)
        return INT_MAX/3; //Um número mto grande, mas não tanto, pra não ter risco de overflow

    if (s.size() == 1) //caso base: |s| = 1
        return (s[0] != c);

    //passo da recursão  
    int n = s.size()/2;
    return min(
        onlyc(s.substr(0, n), c) + goodStr(s.substr(n, n), c+1), 
        onlyc(s.substr(n, n), c) + goodStr(s.substr(0, n), c+1)
    );
}

int main(){
    fast_io;
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        cout << goodStr(s, 'a') << '\n';
    }
}