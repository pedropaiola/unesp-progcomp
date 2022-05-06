/*
Problema: Passwords
Categorias:
    backtracking
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

void backtracking(int ind, string senha, string &padrao, vector<string> &palavras){
    if (ind == padrao.size()){
        cout << senha << endl;
        return;
    }

    if (padrao[ind] == '0')
        for(int i = 0; i < 10; i++)
            backtracking(ind + 1, senha + to_string(i), padrao, palavras);
    else
        for(string s : palavras)
            backtracking(ind + 1, senha + s, padrao, palavras);
}

int main(){
    int n, m, i;
    string s;
    while(cin >> n){
        vector<string> palavras;
        cout << "--\n";

        for(i = 0; i < n; i++){
            cin >> s;
            palavras.push_back(s);
        }

        cin >> m;
        for(i = 0; i < m; i++){
            cin >> s;
            backtracking(0, "", s, palavras);
        }
    }
}