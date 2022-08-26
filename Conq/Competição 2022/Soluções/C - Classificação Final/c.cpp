/*
  Problema C - Classificação Final
  Aqui basta ordenar por pontos, pais e competidor
  Procurar verificando se o pais repete nos próximos da lista
*/

#include <bits/stdc++.h>
using namespace std;

//Struct para representar cada competidor e suas informações (nome, pais e pontuação)
struct registro
{
    string competidor;
    string pais;
    int pontos;
};

struct podium
{
    string pais;
    string competidor;
};


//Função de comparação de dois registros, com base nos critérios dados pelo enunciado
bool compara(registro a, registro b)
{
    if (a.pontos != b.pontos) //Se os competidores não estão empatados
    {
        return a.pontos > b.pontos; //Ordena de forma decrescente pela pontuação
    }
    //Se tiverem empatados
    return a.pais < b.pais; //Desempatada pelo nome do país (ordenando de forma crescente conforme o nome do país) 
}

int main()
{
    int N;

    cin >> N;
    vector<registro> placar;
    registro aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux.competidor >> aux.pais >> aux.pontos; //Lendo dados do competidor
        placar.push_back(aux); //e salvando no vetor 
    }
    //Ordenando placar utilizando a função "compara" que criamos anteriormente
    sort(placar.begin(), placar.end(), compara);


    vector<podium> premios; //Para salvar a resposta
    podium aux1;
    aux1.pais = placar[0].pais;
    aux1.competidor = placar[0].competidor;
    premios.push_back(aux1); // Guardou o 1o lugar

    // Procura segundo e terceiro colocado
    int i = 1;
    int tot = 1;
    bool achousegundolugar = false;

    while (i < (int)placar.size())
    {
        // Verifica se é 2o colocado 
        if ((placar[i].pais != premios[0].pais) && !achousegundolugar) //Se o país é diferente do primeiro colocado e ainda não achamos o segundo lugar
        {
            aux1.pais = placar[i].pais;
            aux1.competidor = placar[i].competidor;
            premios.push_back(aux1); // Guardou o 2o lugar
            achousegundolugar = true;
            tot++;
        }
        else 
        {
            // Verifica se é 3o colocado
            if ((placar[i].pais != premios[0].pais) && //país diferente do primeiro colocado
                (placar[i].pais != premios[1].pais)) //e país diferente do terceiro colocado
            {
                aux1.pais = placar[i].pais;
                aux1.competidor = placar[i].competidor;
                premios.push_back(aux1); // Guardou o 3o lugar
                tot++;
                break;
            }
        }
        i++;
    }
    // Imprime resultado
    cout << tot << endl;
    for (int i = 0; i < tot; i++)
    {
        cout << i + 1 << " " << premios[i].pais << " " << premios[i].competidor << endl;
    }
    return 0;
}