//ORDENAÇÃO CONSIDERANDO VALOR ABSOLUTO, USANDO SOBRECARGA DE OPERADOR
#include<bits/stdc++.h>

using namespace std;

//A sobrecarga de operadores para tipos primitivos (int, double, char, ...) não vale muito a pena, pois temos
//que escrever uma classe auxiliar apenas para representar esses tipos e permitir a sobrecarga de operadores.
//Mas o método é bastante útil para classes em geral, como vemos no outro exemplo em que usamos um pair
class Integer
{
	int i;
	
	public:
	//Essas funções são apenas pra fazer a brincadeira de int => Integer e de Integer => int
	//é interessante ver que também estamos trabalhando com sobrecarga de operadores aqui, sendo
	//eles o operador de atribuição (=) e o de casting (implícito) int()
	Integer() : i(0) {}
	Integer(int x) : i(x) {}
	operator=(const int &x) { i = x; }
	operator int() { return i; } //Isso permite que nossa classe Integer seja convertida para int quando necessário de forma implicita
};

//Sobrecarga do operador < para quando fazemos uma comparação do tipo a < b (sendo a e b do tipo Integer)
int operator<(Integer& a, Integer& b) 
{
	//O original seria algo como "return a < b";
	return abs(a) < abs(b); //comparando valores absolutos
}

int main()
{
	vector<Integer> vet = {-4, 2, -1, 4, 9, -2, -10, 20};
	sort(vet.begin(), vet.end());
	for(int i = 0; i < vet.size(); i++)
		cout << vet[i] << " ";
}
