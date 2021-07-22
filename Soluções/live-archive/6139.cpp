/*
Problema: I - Interval Product
Categorias:
	data structure > segment tree
	maratona > nacional 2012 
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<iostream>
#include<vector>

using namespace std;

char vetor[100001];
char arvore[300000];

void atualiza(int no, int i, int j, int pos, char valor)
{
	if (i == j) {
		vetor[pos] = valor;
		if (valor < 0)
			arvore[no] = -1;
		else if (valor > 0)
			arvore[no] = 1;
		else
			arvore[no] = 0;	
	}	
	else
	{
		int esquerda = 2*no;
		int direita = 2*no + 1;
		
		int meio = (i + j)/2;
		
		if (pos <= meio)
			atualiza(esquerda, i, meio, pos, valor);
		else
			atualiza(direita, meio+1, j, pos, valor);
			
		arvore[no] = arvore[esquerda] * arvore[direita];
	}
}

int consulta(int no, int i, int j, int A, int B){
	if (A <= i && j <= B)
		return arvore[no];
	
	if (i > B || A > j)
		return 1; 		 //N�o far� diferen�a no resultado final
	
	int esquerda = 2*no;
	int direita = 2*no + 1;
	
	int meio = (i + j)/2;
	
	char resposta_esquerda = consulta(esquerda, i, meio, A, B);
	char resposta_direita = consulta(direita, meio+1, j, A, B);
	
	return resposta_esquerda * resposta_direita;
}

int sgn(int x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

int main()
{
	int n, k, A, B, v, i, prod;
	char c;
	
	while(cin >> n >> k){	
		//vetor.resize(n + 1);
		//arvore.resize(2*n);
		
		for(i = 1; i <= n; i++)
		{
			cin >> v;
			atualiza(1,1,n,i,sgn(v));
		} 
		
			
		for (i = 0; i < k; i++){
			cin >> c;
			if (c == 'C'){
				cin >> A >> v;
				atualiza(1,1,n,A,sgn(v));
			} else {
				cin >> A >> B;
				prod = consulta(1,1,n,A,B);
				if (prod > 0)
					cout << "+";
				else if (prod < 0)
					cout << "-";
				else
					cout << "0";
			}
		}
		cout << endl;
	}	
}
