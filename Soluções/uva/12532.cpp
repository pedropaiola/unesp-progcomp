/*
Problema: Interval Product
Categorias:
	data structure > bit
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<iostream>
#include<vector>

using namespace std;

char vetor[100001];
int arvNeg[100001];
int arvZero[100001];

int read(int idx, int tree[]){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val, int tree[], int MaxVal){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main()
{
	int n, k, A, B, v, i, prod;
	char c;
	
	while(cin >> n >> k){	
		//vetor.resize(n + 1);
		//arvore.resize(2*n);
		for(i = 1; i <= n; i++){
			arvNeg[i] = arvZero[i] = 0;
		}
		
		for(i = 1; i <= n; i++)
		{
			cin >> v;
			vetor[i] = v;
			if (vetor[i] < 0)
				update(i,1,arvNeg, n);
			else if (vetor[i] == 0)
				update(i,1,arvZero, n);
		} 
		
		/*for (i = 1; i <= n; i++)
			cout << arvNeg[i];
		cout << endl;
		for (i = 1; i <= n; i++)
			cout << arvZero[i];*/
				
		for (i = 0; i < k; i++){
			cin >> c;
			if (c == 'C'){
				cin >> A >> v;
				
				if (vetor[A] < 0)
					update(A,-1,arvNeg, n);
				else if (vetor[A] == 0)
					update(A,-1,arvZero, n);
				
				vetor[A] = v;
				if (vetor[A] < 0)
					update(A,1,arvNeg, n);
				else if (vetor[A] == 0)
					update(A,1,arvZero, n);
				
			} else {
				cin >> A >> B;
				prod = read(B,arvZero) - read(A-1,arvZero);
				//cout << "(qtd0 " << prod << ")";
				if (prod > 0)
					cout << "0";
				else {
					prod = read(B,arvNeg) - read(A-1,arvNeg);
					//cout << "(qtd- " << prod << ")";
					if (prod % 2 == 0)
						cout << "+";
					else
						cout << "-";
				}
			}
		}
		cout << endl;
	}	
	
}
