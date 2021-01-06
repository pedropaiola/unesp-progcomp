/*
Problema: The Skyline Problem
Categorias:
	math > geometry
Dificuldade: facil
Descricao:
Dica: line sweep
Autor: Paiola
*/
#include<bits/stdc++.h>
#define INICIO 1
#define FIM 0
#define x(t) get<0>(t)
#define alt(t) get<1>(t)
#define ehInicio(t) get<2>(t)

using namespace std;

//Desempate pelo segundo elemento da tupla (referente a altura)
//Isso pq se tivermos para o mesmo x vários retângulos começando com alturas diferentes,
//só iremos printar a maior (isso se todos não estiverem dentro de um retângulo maior)
//Ex: (1 10 x) (1 20 y) (1 15 z) =ordenando=> (1 20 y) (1 15 z) (1 10 x)
//Sem ordenar printaria 1 10 1 20 ...
bool comp(const tuple<int,int,int>& t1, const tuple<int,int,int>& t2){
    if (x(t1) == x(t2)){
        return alt(t1) > alt(t2);
    }
    return x(t1) < x(t2);
}

int main(){
    int l, h, r;
    vector<tuple<int, int, int> > vet; //(x, h, inicio ou fim)
    while(cin >> l >> h >> r){
        vet.push_back({l,h,INICIO});    //Preenchendo vetor para o line sweep
        vet.push_back({r,h,FIM});
    }
    sort(vet.begin(), vet.end(), comp); //Ordenando para poder fazer a varredura
    multiset<int> alturas;
    alturas.insert(0);  //menor altura possível
    for(int i = 0; i < vet.size(); i++){
        if (ehInicio(vet[i])){
            if (alt(vet[i]) > -(*alturas.begin())){ //se o retângulo que acabou de entrar é maior que qualquer outro no ponto x
                cout << x(vet[i]) << " " << alt(vet[i]) << " "; //então vamos imprimir x e alt
            }
            alturas.insert(-alt(vet[i])); //Inserindo a altura no conjunto (com sinal invertido, para ficar em ordem decrescente)
        }
        else
        {
            int alturaAnterior = -(*alturas.begin()); 
            alturas.erase(alturas.lower_bound(-alt(vet[i]))); //Retângulo saindo da varredura, então vamos tirar essa altura do conjunto 
            //OBS: não podemos fazer alturas.erase(-alt(vet[i])) pq isso apagaria TODAS as ocorrências desse valor de altura
            if (alturaAnterior != -(*alturas.begin())){ //Só imprimimos alguma coisa se houve alteração no maior retângulo atual
                cout << x(vet[i]) << " " << -(*alturas.begin());
                if (i < vet.size() - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }
}