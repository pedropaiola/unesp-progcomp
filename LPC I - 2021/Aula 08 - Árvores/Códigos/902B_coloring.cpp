/*
Problema: Coloring a Tree
Categorias:
    graphs > specials > tree
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define QTDE_VERTICES 10001
    
using namespace std;
    
vector<int> arvore[QTDE_VERTICES];
int cor_desejada[QTDE_VERTICES];
    
void aresta(int u, int v){    //u é pai de v
    arvore[u].push_back(v);
}
    
int pintar(int no, int corAtual)
{
    int passos = 0;
    if (cor_desejada[no] != corAtual)
    {
        passos = 1;
        corAtual = cor_desejada[no];
    }
    for(auto v: arvore[no])
        passos += pintar(v, corAtual);
    
    return passos;
}
    
int main()
{
    int n, i, pai;
    cin >> n;
    for(i = 2; i <= n; i++)
    {
        cin >> pai;
        aresta(pai, i);
    }
    for(i = 1; i <= n; i++)
        cin >> cor_desejada[i];
    cout << pintar(1, 0) << endl;
}