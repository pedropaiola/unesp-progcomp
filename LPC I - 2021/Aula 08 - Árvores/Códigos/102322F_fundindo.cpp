/*
Problema: Fundindo Árvores
Categorias:
    graphs > specials > tree
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<iostream>

using namespace std;

typedef struct{
	int filho_esq;
	int filho_central;
} arvoreC;

typedef struct{
	int filho_central;
	int filho_dir;
} arvoreD;

int sequenciaCentraisC[10000];
int sequenciaCentraisD[10000];

//Retorna a sequência máxima de nós centrais a partir de um nó da árvore
inline int seqMax(arvoreC arvC[], int no){
	if (sequenciaCentraisC[no] != -1)
		return sequenciaCentraisC[no];
	if (no == -1){
		return 0;
	}

	int qtde = 1 + seqMax(arvC, arvC[no].filho_central);
	sequenciaCentraisC[no] = qtde;
	return qtde;
}

inline int seqMax(arvoreD arvD[], int no){
	if (sequenciaCentraisD[no] != -1)
		return sequenciaCentraisD[no];
	if (no == -1){
		return 0;
	}

	int qtde = 1 + seqMax(arvD, arvD[no].filho_central);
	sequenciaCentraisD[no] = qtde;
	return qtde;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	arvoreC arvC[10000];
	arvoreD arvD[10000];
	int nC, nD, v, v1, v2, i;
	int maxC = 0, maxD = 0, maxCRaiz, maxDRaiz;
	
	cin >> nC;
	for(i = 0; i < nC; i++){
		cin >> v >> v1 >> v2;

		sequenciaCentraisC[v-1] = -1;
		arvC[v-1].filho_esq = v1 - 1;
		arvC[v-1].filho_central = v2 - 1;
	}
	
	cin >> nD;
	for(i = 0; i < nD; i++){
		cin >> v >> v1 >> v2;
		sequenciaCentraisD[v-1] = -1;
		arvD[v-1].filho_central = v1 - 1;
		arvD[v-1].filho_dir = v2 - 1;
	}
	
	//Apenas nós centrais podem se fundir (devido a estrutura das árvores), dessa forma queremos encontrar
	//a sequência máxima de nós centrais nas duas árvores, só tomando o cuidado de considerar que temos que
	//manter uma estrutura de árvore, com apenas uma raiz, um nó não pode ser filho de dois pais não fundidos.
	//Para isso, não pode acontecer de uma sequência qualquer de uma árvore se fundir a uma qualquer da outra,
	//uma delas deve começar da raiz da árvore em questão
	
	maxCRaiz = seqMax(arvC, 0);
	for(i = 0; i < nC; i++)
		maxC = max(maxC, seqMax(arvC, i));
	maxDRaiz = seqMax(arvD, 0);
	for(i = 0; i < nD; i++)
		maxD = max(maxD, seqMax(arvD, i));
		
	cout << (nD + nC - max(min(maxCRaiz, maxD),min(maxDRaiz, maxC)))<< endl;
}