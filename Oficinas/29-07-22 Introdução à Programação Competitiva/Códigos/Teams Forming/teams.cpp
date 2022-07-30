#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i, aux;
    vector<int> a;  //Criando um vector de inteiros

    cin >> n;   
    //Lendo a pontuação de cada pessoa  
    for(i = 0; i < n; i++){
        cin >> aux;         //Lendo a pontuação em uma variável auxiliar
        a.push_back(aux);   //e armazenando no vetor (sempre adicionada ao final = push_back)
    }

    //Ordenando o vetor
    sort(a.begin(), a.end());

    //A resposta é gulosa, formamos duplas com aqueles que tem a pontuação mais próxima,
    //forçando o primeiro (menor conhecimento) a chegar no conhecimento do próximo. Sendo assim,
    //basta somar as diferenças de pontuação par a par
    int resp = 0;
    //Percorrendo as posições i = 1, 3, 5, ...
    for(i = 1; i < n; i += 2) 
        resp += a[i] - a[i-1]; //A posição anterior é o parceiro de dupla. Obs: podemos acessar um vector igual acessamos um vetor/array normal
    
    cout << resp << "\n";
}