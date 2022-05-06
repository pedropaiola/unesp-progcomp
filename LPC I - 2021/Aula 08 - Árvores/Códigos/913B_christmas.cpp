/*
Problema: Christmas Spruce
Categorias:
    graphs > specials > tree
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define QTDE_VERTICES 1001
    
using namespace std;
    
vector<int> arvore[QTDE_VERTICES];
    
void aresta(int u, int v){  
    arvore[u].push_back(v);
}
    
bool ehFolha(int no)
{
    return arvore[no].empty();
}
    
bool isSpruce(int no)
{
    if (ehFolha(no))
        return true;
        
    int qtdeFolhas = 0, i;
    for(auto v: arvore[no])
    {
        if (ehFolha(v))
            qtdeFolhas++;
    }
    if (qtdeFolhas < 3)
        return false;
    
    for(auto v: arvore[no])
    {
        if (!isSpruce(v))
            return false;
    }
    return true;
}
    
int main()
{
    int n, i, p;
    cin >> n;
    for(i = 2; i <= n; i++)
    {
        cin >> p;
        aresta(p, i);
    }
    cout << (isSpruce(1) ? "Yes" : "No") << endl;
}