/*
Problema: I AM VERY BUSY
Categorias:
	greedy > schedule
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define inicio second
#define fim	first

using namespace std;

int main()
{
	int t, n, i, qtdeAtiv;
	vector<pair<int, int> > tarefas;
	pair<int, int> parAux;
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		tarefas.clear();
		for(i = 0; i < n; i++)
		{
			cin >> parAux.inicio >> parAux.fim; //real: cin >> parAux.second >> parAux.first, a defini��o de constantes pd ajudar muito na leitura do c�digo
			tarefas.push_back(parAux);
		}
		//Ordenando pelas tarefas pelo tempo do t�rmino
		sort(tarefas.begin(), tarefas.end());
		qtdeAtiv = 1;
		parAux = tarefas[0];
		//Considerando que a primeira tarefa � a que tem o menor tempo de t�rmino, tentamos escalonar a pr�xima
		//que come�a depois desse tempo (e que tbem tenha menor tempo de t�rmino, o que � garantido pela ordena��o)
		for(i = 1; i < n; i++)
		{
			if (tarefas[i].inicio >= parAux.fim) //parAux representa a ultima tarefa que foi realizada
			{
				qtdeAtiv++;
				parAux = tarefas[i];
			}
		}
		cout << qtdeAtiv << endl;
	}
}
