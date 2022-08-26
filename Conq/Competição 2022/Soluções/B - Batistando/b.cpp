/*
  Problema A - Aperto de Mão
  Devido ao número de lojas e os preços dos produtos não serem muito valores
  muito grandes, conseguimos resolver este problema por força bruta, testando
  todas possibilidades de valor em carteira (começando por R$ 1,000), e vendo 
  se com esse valor o José consegue comprar pelo menos K itens, se conseguir, 
  então esta é a resposta.
  OBS: Não podemos aplicar busca binária neste problema porque não temos uma função monótona.
*/
#include<bits/stdc++.h>

using namespace std;

//Função auxiliar para verificar quantos itens conseguimos comprar
//com x reais (seguindo a estratégia boba do José)
int consegueComprar(vector<int> &lojas, int x){
    int resp = 0;
    //Para cada item de valor c (seguindo a ordem que foi dada na entrada)  
    for(int c : lojas){
        //Se temos dinheiro para comprar este item
        if (c <= x){
            //Compramos
            resp++;
            x -= c;
        }
    }
    return resp; //Retorna a quantidade de itens que conseguimos comprar
}

int main(){
    int n, k, x, aux, soma = 0;
    vector<int> lojas;
    cin >> n >> k;

    //Leitura da entrada
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        //Somando todos os valores, pq este é o máximo de dinheiro que podemos precisar (no pior caso)
        soma += aux;  
        lojas.push_back(aux); //Preenchendo o vector
    }

    //Para cada x (valor em carteira) possível
    for(x = 1; x <= soma; x++){
        if (consegueComprar(lojas, x) >= k) //Se conseguirmos comprar pelo menos k itens
        {
            //Este é o valor que queremos. Imprimos a resposta e quebramos o laço
            cout << x << "\n";
            break;
        }
    }
}