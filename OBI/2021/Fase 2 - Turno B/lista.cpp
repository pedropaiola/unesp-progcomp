#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x, i, j;
    vector<int> v;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }


    i = 0;      //Apontando para o primeiro item do vetor
    j = n-1;    //Apontando para o último
    int op = 0, se = v[i], sd = v[j];
    //op = número de operações
    //mantém a soma das posições à esquerda
    //mantém a soma das posições a direita
    while(i <= j){
        if (se == sd)
        {
            //Se as somas coincidem, não precisamos fazer uma operação, pois
            //os elementos opostos são iguais (ou já conseguimos igualá-los)
            i++; j--;
            se = v[i];
            sd = v[j];
        }
        else if (se < sd){
            //Se a soma da esquerda é menor, então somados a posição
            //da esquerda com a próxima, esperando nos igualar à soma da direita
            i++;
            se += v[i];
            op++;
            if (i == j)
                break;
        } else {
            //Se a soma da direita é menor, a ideia é análoga ao item anterior
            j--;
            sd += v[j];
            op++;
            if (i == j)
                break;
        }
    }
    cout << op << "\n";
}