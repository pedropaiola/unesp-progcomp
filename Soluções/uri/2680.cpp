/*
Problema: Ecologia
Categorias:
	dynamic programming
Dificuldade: muito dificil
Descricao:
Dica: transformar em um problema de minimização
Autor: Paiola e Comini
*/
#include <bits/stdc++.h>

using namespace std;

//Variáveis do problema
int n, m;
int original[50][50];
int mat[50][50], maximo;
int valorMin = 999999999, arvoresSalvas = 0;
double media;

priority_queue<tuple<int,int,int> > heap;
unordered_map<bitset<2500>, int> memo;

bool ehValido(int i){
	return ((i >= 0) && (i < n));
}

int posBit(int i, int j)
{
	return i*n + j;
}

pair<int, int> coord(int bit)
{
	pair<int, int> p;
	p.first = bit / n;
	p.second = bit % n;
	return p;
}

//Coração do programa, encontra a area com a menor soma (na matriz alterada) usando backtracking e PD
int backtracking(bitset<2500> &area, int i, int j, int soma)
{
	area[posBit(i,j)] = 1;
		
	if (memo.count(area)){	//Se já passamos por esse caminho
		area[posBit(i,j)] = 0;
		return memo[area];  //Retornamos o valor salvo
	}
		
	soma += mat[i][j];	
	
	if (soma > valorMin)	//Se a soma dessa área é maior do que a menor já encontrada
	{	
		area[posBit(i,j)] = 0;
		return soma;		//não há porque continuar explorando esse caminho
	}
	
	int tam = area.count();
	int qtdeElementos = tam;
	
	if (tam < m)			//Se ainda não temos uma área de tamanho m
	{
		pair<int, int> pos;
		int valorMinimo = 999999999;
		
		//Exploramos todas as possibilidades (tentando adicionar uma posição adjacente
		//a qualquer uma das posições já inclusas dentro da nossa área)
		for(int k = 0; k < area.size(); k++){
			if (area.test(k))
			{
				qtdeElementos--;
				pos = coord(k);
				if (ehValido(pos.first - 1) && !area.test(posBit(pos.first - 1, pos.second)))
					valorMinimo = min(valorMinimo, backtracking(area, pos.first - 1, pos.second, soma));
				if (ehValido(pos.first + 1) && !area.test(posBit(pos.first + 1, pos.second)))
					valorMinimo = min(valorMinimo, backtracking(area, pos.first + 1, pos.second, soma));
				if (ehValido(pos.second - 1) && !area.test(posBit(pos.first, pos.second - 1)))
					valorMinimo = min(valorMinimo, backtracking(area, pos.first, pos.second - 1, soma));
				if (ehValido(pos.second + 1) && !area.test(posBit(pos.first, pos.second + 1)))
					valorMinimo = min(valorMinimo, backtracking(area, pos.first, pos.second + 1, soma));
					
				if (!qtdeElementos)
					break;
			}
		}
		//a menor soma que podemos encontrar por esse caminho
		soma = valorMinimo;		
	}
	else if (soma < valorMin)	//se a área já está completa (com tamanho m) e é a melhor que temos até agora
	{
		valorMin = soma;						//alteramos o valorMin
		arvoresSalvas = -valorMin + m*maximo;	//e corrigimos o valor para obter o número de árvores salvas (revertendo as transformações feitas na matriz)
	}
	memo[area] = soma;				//Salvando o valor encontrado nesse caminho
	area[posBit(i,j)] = 0;
	return soma;
}

int resolver(){
	//essa função basicamente chama o backtracking para cada uma das posições
	//inseridas na heap, e no final retorna o número máximo de árvores que podem
	//ser salvas
	bitset<2500> area;
	int i, j;
	while(!heap.empty())
	{
		i = get<1>(heap.top());
		j = get<2>(heap.top());
		heap.pop();
		backtracking(area, i, j, 0);	
	}

	return arvoresSalvas;
}

int main(){	
	ios_base::sync_with_stdio(false);	
    cin.tie(NULL);						//com isso o cin fica mais rápido que o scanf até (pelo menos nesse problema)
	int i, j, minimo = 999999999;
	cin >> n >> m;
	media = 0;
	maximo = 0;

	//Lendo a matriz, somando seus valores para o cálculo da média e encontrando o mínimo e o máximo
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
		{
			cin >> original[i][j];
			media += original[i][j];
			maximo = max(maximo, original[i][j]);
			minimo = min(minimo, original[i][j]);
		}
	}
	if (minimo != maximo)
	{
		media /= float(n*n);	//Cálculo da média
		
		//Criando matriz alterada e inserindo os elementos na heap
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
			{
				mat[i][j] = -original[i][j] + maximo;
				if (original[i][j] >= media)
					heap.push(make_tuple(-mat[i][j], i, j));
			}
		}
		cout << resolver() << endl;	
	}
	else //Caso particular em que todos os elementos são iguais
	{
		cout << m*maximo << endl;
	}
}