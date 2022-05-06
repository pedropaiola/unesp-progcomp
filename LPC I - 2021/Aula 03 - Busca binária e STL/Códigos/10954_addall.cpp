/*
Problema: Add All
Categorias:
	data structure > priority queue
	greedy
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	priority_queue<int> heap;
	int n, i, x, y, custo;
	
	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		for(i = 0; i < n; i++)
		{
			cin >> x;
			heap.push(-x);
		}
		custo = 0;
		while(!heap.empty()){
			x = -heap.top();
			heap.pop();
			if (heap.empty())
				break;
			y = -heap.top();
			heap.pop();
			custo += x + y;
			heap.push(-x-y);
		}
		cout << custo << endl;
	}
}