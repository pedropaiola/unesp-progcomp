/*
Problema: Nice Binary Trees
Categorias:
    graphs > specials > tree
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;
    
int resp, ind;
string s;
      
void dfs(int nivel)
{
    if (ind >= s.size())
        return;
    char atual = s[ind];
    ind++;
    resp = max(resp, nivel);
    
    if (atual == 'l')
        return;
    dfs(nivel+1);
    dfs(nivel+1);
}
    
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ind = resp = 0;
        dfs(0);
        cout << resp << endl;
    }	
} 