/*
  Problema H - Haja interruptores
  Solução gulosa, seguindo a estratégia descrita no enunciado, pode-se
  perceber que ao final de uma segunda passada pelos interruptores ele
  retornará ao estado inicial, entrando em um ciclo. Sendo assim, a solução
  consiste em realizar estas duas passadas, procurando uma situação em que
  todas as lãmpadas estejam apagadas. Caso essa situação não ocorra, então
  é porque o problema não tem solução.
*/
#include<bits/stdc++.h>

using namespace std;

int qtdeInt, qtdeLamp, qtdeLampAcesas;
bool lampadaAcesa[1000];
int interruptores[1000][1000];
int lampAfetadas[1000];

int resolver()
{
	int i, j, pos;
	int qtdeLampApagadas = qtdeLamp - qtdeLampAcesas; //Qtde de lâmpadas apagadas no começo
	int mov = 0;
	
	if (qtdeLampApagadas == qtdeLamp) //Caso em que o estado inicial já é a solução
		return mov;
		
	for(i = 0; i < qtdeInt; i++) //Primeira passada
	{
		mov++;
		for(j = 0; j < lampAfetadas[i]; j++){ //Acionando interruptores
			pos = interruptores[i][j];
			lampadaAcesa[pos] = !lampadaAcesa[pos];
			if (!lampadaAcesa[pos]) //Atualizando número de lâmpadas apagadas
				qtdeLampApagadas++;
			else
				qtdeLampApagadas--;
		}
		if (qtdeLampApagadas == qtdeLamp) //Se todas as lâmpadas estiverem apagadas, é a solução
			return mov;
	}
	for(i = 0; i < qtdeInt; i++){ //Segunda passada
		mov++;
		for(j = 0; j < lampAfetadas[i]; j++){
			pos = interruptores[i][j];
			lampadaAcesa[pos] = !lampadaAcesa[pos];
			if (!lampadaAcesa[pos])
				qtdeLampApagadas++;
			else
				qtdeLampApagadas--;
		}
		if (qtdeLampApagadas == qtdeLamp)
			return mov;
	}
	//Se chegar aqui, é pq não encontramos solução
	return -1;
}

int main(){
	int i, j;
	
	scanf("%d %d", &qtdeInt, &qtdeLamp);
	for(i = 0; i < qtdeLamp; i++)
		lampadaAcesa[i] = false;
	
	scanf("%d", &qtdeLampAcesas);
	
	for(i = 0; i < qtdeLampAcesas; i++)
	{
		scanf("%d", &j);
		lampadaAcesa[j-1] = true;
	}
	
	for(i = 0; i < qtdeInt; i++)
	{
		scanf("%d", &lampAfetadas[i]);
		for(j = 0; j < lampAfetadas[i]; j++)
		{
			scanf("%d", &interruptores[i][j]);
			interruptores[i][j]--;
		}
	}
	printf("%d\n",resolver());
}
