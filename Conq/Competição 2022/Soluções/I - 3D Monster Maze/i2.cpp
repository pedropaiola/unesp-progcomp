/*
  Problema I - 3D Monster Maze
  Problema padrão de backtracking (pode ser encarado como um problema
  de recursão ou de busca em profunidade). Percorrer labirinto até achar
  a saída. Informação importante: só existe um caminho até a saída,
  o que simplifica ainda mais o problema.
*/
#include<bits/stdc++.h>

using namespace std;

string lab[101]; //vetor de strings para armazenar o labiritindo
int n;

//Vetor com possíveis movimentos (direita, esquerda, baixo, cima),
//a ideia é facilitar a codificação do problema, diminuindo a qtde
//de código necessária (e ajudando a generalizar futuras implementações de backtracking)
pair<int,int> mov[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; 

//Obter uma nova posição a partir de um dos movimentos possíveis
pair<int, int> movimentar(pair<int,int> pos, int sentido){
    pos.first += mov[sentido].first;
    pos.second += mov[sentido].second;
    return pos;
}

//Verificando se a posição é válida (dentro dos limites e não é parede)
bool ehValida(pair<int, int> pos){
    if (pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= n)
        return false;
    return ((lab[pos.first][pos.second] == '.') || (lab[pos.first][pos.second] == 'S'));
}

//Backtracking para percorrer labirinto. Retorna true se encontramos um caminho
bool percorrerLab(pair<int, int> pos){
    for(int sentido = 0; sentido < 4; sentido++) //para cada movimento possível 
    {
        pair<int, int> newPos = movimentar(pos, sentido); //calculamos a nova posição

        if (!ehValida(newPos)) //verificamos se ela é válida
            continue;          //se não for vamos para a próxima iteração

        if (lab[newPos.first][newPos.second] == 'S') //Se já chegamos na saída
            return true;                             //retornamos true

        //Se ainda não é a saída
        lab[newPos.first][newPos.second] = 'C'; //Marcamos essa posição como parte do nosso caminho (o que também impede de voltar para essa posição)
        if (percorrerLab(newPos))   //Continuamos a percorrer o labirinto, e
            return true;            //se retornar true é pq por aqui conseguimos chegar na saída (logo já podemos encerrar a busca)
        //Se não retornou true, é pq esse caminho não chegou na saída
        lab[newPos.first][newPos.second] = '.'; //então tiramos essa posição do caminho, e continuamos com nosso algoritmo, tentando outra possibilidade
    }
    //Se tentamos todos os movimentos possíveis e nenhum chegou na saída, então este
    //é um ramo "inválido", que não nos dá uma solução, logo podemos retornar false
    return false;
}

int main(){
    pair<int, int> ini;
    cin >> n;
    n += 2;
    for(int i = 0; i < n; i++){
        cin >> lab[i];
        for(int j = 0; j < n; j++){
            if (lab[i][j] == 'I'){
                ini.first = i;
                ini.second = j;
            }
        }
    }
    percorrerLab(ini);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (lab[i][j] == '#')
                cout << ".";
            else
                cout << lab[i][j];
        }
        cout << "\n";
    }
}