/*
Problema: Elevator Trouble
Categorias:
    graphs > bfs
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXF 1000000
#define andar first
#define passos second
    
using namespace std;
    
bool analisado[MAXF+1];
int f, s, g, u, d;
    
int passosNecessarios()
{
    int passos = 0, proxAndar;
    pair<int, int> andarAtual;
    queue<pair<int, int> > andares;
    andares.push({s, 0});
    analisado[s] = true;
    while(!andares.empty())
    {
        andarAtual = andares.front();
        andares.pop();
        if (andarAtual.andar == g)
            return andarAtual.passos;
        
        proxAndar = andarAtual.andar - d;
        if (proxAndar > 0 && !analisado[proxAndar])
        {
            analisado[proxAndar] = true;
            andares.push({proxAndar, andarAtual.passos + 1});
        }
        proxAndar = andarAtual.andar + u;
        if (proxAndar <= MAXF && !analisado[proxAndar])
        {
            analisado[proxAndar] = true;
            andares.push({proxAndar, andarAtual.passos + 1});
        }
        
    }
    return -1;
}
    
int main()
{
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);	
    cin >> f >> s >> g >> u >> d;
    //for(int i = 0; i <= f; i++)
    //	analisado[i] = false;
    int resp = passosNecessarios();
    if (resp == -1)
        cout << "use the stairs" << endl;
    else
        cout << resp << endl;
} 