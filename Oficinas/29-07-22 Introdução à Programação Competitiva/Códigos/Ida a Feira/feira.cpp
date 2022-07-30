#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, i;

    cin >> t;

    while(t--)  //Para cada caso de teste: Enquanto t > 0, decrementa o t e executa o laço. Quando t == 0, encerra
    { 
        int n, m, qtde;
        map<string, double> precos; //map para armazenar os preços de cada item, em que o nome do item é a chave
        string item;
        double valor, total = 0;

        cin >> n;
        //Lendo cada um dos itens e seus valores unitários
        for(i = 0; i < n; i++){
            cin >> item >> valor;
            precos[item] = valor;   //Armazenando no map
        }

        //Lendo a lista de compras
        cin >> m;
        for(i = 0; i < m; i++){
            cin >> item >> qtde;
            total += precos[item] * qtde;
        }

        printf("R$ %.2lf\n", total);
    }
}