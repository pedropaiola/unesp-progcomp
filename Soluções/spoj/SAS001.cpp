/*
Problema: Apoorv and Maximum Inversion
Categorias:
	data structure > bit
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 500000
#define ll long long int

using namespace std;

ll getSum(ll BITree[], ll index) 
{ 
    ll sum = 0;
    while (index > 0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(ll BITree[], ll n, ll index, ll val) 
{ 
    while (index <= n) 
    { 
       BITree[index] += val; 
       index += index & (-index); 
    } 
} 
  
//Precisamos construir uma BIT com uma posição para cada elemento,
//mas como os elementos podem variar mto e serem até negativos, vamos
//primeiro mapeá-los para um intervalo menor e positivo
void convert(ll arr[], ll n) 
{ 
    //Vamos criar uma cópia ordenada do vetor
    ll temp[n]; 
    for (ll i=0; i<n; i++) 
        temp[i] = arr[i]; 
    sort(temp, temp+n); 
  
    //E então converter os números baseados na posição que eles ocupam
    //no vetor ordenado
    for (ll i=0; i<n; i++) 
    { 
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1; 
    } 
} 
  
void getInvCount(ll arr[], ll n, ll p) 
{ 
    ll invcount = 0, invcountMax = 0;   
    ll idx;
    convert(arr, n); 
    
    ll BIT[n+1]; //Criamos uma bit com uma possição para cada elemento
    for (ll i=1; i<=n; i++) 
        BIT[i] = 0; 
  
    //Caso padrão:Percorrendo o vetor de trás para frente, vamos armazenar na BIT
    //quantas vezes cada valor apareceu. Com isso, quando estiver no
    //elemento arr[i], se olharmos para BIT[arr[i] - 1], saberemos
    //quantos elementos menores que arr[i] já aparecerem dps da posição i.
    //Em outras palavras, quantas inversões ocorreram.
    //Agora aqui queremos apenas janelas de tamanho p. Para isso, quando já tivermos uma
    //janela de tamanho p e dermos um passo para trás (i--), iremos tirar da BIT o valor
    //arr[i+p] e recalcular as inversões
    for (ll i=n-1; i>=0; i--) 
    { 
        if (i + p < n)
        {
            updateBIT(BIT, n, arr[i+p], -1); //tira a ocorrência de arr[i+p]
            //Para recalcular as inversões retiramos todas as ocorrências encontradas até
            //agora (-getSum(BIT, n)), voltamos as inversões posteriores ao valor
            //arr[i+p] (agora corrigido, pq tiramos as ocorrências dos elementos posteriores a ele),
            //e por fim, adicionamos as inversões a partir da nossa posição atual.  
            invcount += getSum(BIT, arr[i]-1) - getSum(BIT, n) + getSum(BIT, arr[i + p]);  
            updateBIT(BIT, n, arr[i], 1);  
            if (invcount >= invcountMax){
                invcountMax = invcount;
                idx = i;
            }
        }
        else //Caso base, mais simples, antes de termos que nos preocupar em retirar elementos da contagem
        {
            updateBIT(BIT, n, arr[i], 1);  
            invcount += getSum(BIT, arr[i]-1); //Conta as inversões
        }
    } 
    cout << idx+1 << " " << invcountMax;
} 

int main(){
    ll n, p, i;
    ll arr[MAXN];
    cin >> n >> p;
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    getInvCount(arr, n, p);
}