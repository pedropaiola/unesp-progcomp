//ORDENAÇÃO DE PONTOS, USANDO FUNCTOR
//a ideia aqui vai ser ordenar os pontos (classe criada Ponto) de um vetor, considerando sua distância
//a um ponto pivô. Ou seja, ordenaremos os pontos por ordem crescente de distância a esse ponto pivô
#include<bits/stdc++.h>

using namespace std;

const pair<int, int> pivo(4, 4);
struct Ponto{
	pair<int, int> coord;
	
	Ponto(int x, int y){
		coord = {x, y};
	}

	Ponto(pair<int, int> p){
		coord = p;
	}

	int x(){
		return coord.first;
	}

	int y(){
		return coord.second;
	}

	//Sobrecarga do operador < para quando fazemos uma comparação do tipo (*this) < b
	bool operator<(Ponto &b) 
	{
		int dA = (x() - pivo.first)*(x() - pivo.first) + (y() - pivo.second)*(y() - pivo.second);
		int dB = (b.x() - pivo.first)*(b.x() - pivo.first) + (b.y() - pivo.second)*(b.y() - pivo.second);
		return dA < dB;
	}

};

//Outro exemplo de sobrecarga interessante, do operador <<.
//No caso, estamos querendo usar esse operador para a impressão de um Ponto através de um cout (um objeto ostream)
//Dessa forma quando fizermos cout << ponto << ..., é como se automaticamante ele fizesse cout << "(" << ponto.x() << "," << ponto.y() << ")" ...
ostream& operator<<(ostream &os, Ponto &p)
{
	os << "(" << p.x() << "," << p.y() << ")";
	return os;
}

int main()
{
	vector<Ponto> vet = {{0,0}, {1,2}, {5,4}, {4,4}, {3,3}, {-1,2}, {4,5}};

	sort(vet.begin(), vet.end()); 
	
	for(int i = 0; i < vet.size(); i++)
		cout << vet[i] << " ";	//devido a sobrecarga do operador<< bastou mandarmos o ponto pro cout que a impressão já foi feita como definimos
}
