#include<bits/stdc++.h>

using namespace std;

vector<int> moedas = {50, 25, 10, 5, 1};
vector<int> melhorSolucao;
int qtdeMoedas = INT_MAX;

void troco(int x, vector<int> &solucaoAtual){
    //Se já tem solução melhor  
    if (solucaoAtual.size() >= qtdeMoedas)
        return;

    //Se é uma solução
    if (x == 0){
        melhorSolucao = solucaoAtual;
        qtdeMoedas = solucaoAtual.size();
    }

    //Ainda não chegamos na solução, então tentamos adicionar mais uma moeda
    //Começando da maior para a menor
    for(int m : moedas){
        if (m > x)
            continue;
        solucaoAtual.push_back(m);
        troco(x-m, solucaoAtual);
        solucaoAtual.pop_back();
    }
}

int main(){
    int x;
    vector<int> s;

    cin >> x;
    troco(x, s);

    cout << "Qtde de moedas usadas: " << qtdeMoedas << endl;
    for(int m : melhorSolucao)
        cout << m << " ";
}