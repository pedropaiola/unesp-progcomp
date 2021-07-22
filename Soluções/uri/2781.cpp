/*
Problema: Camara de Compensacao
Categorias:
	adhoc
Dificuldade: facil
Descricao: testando fastscan
Dica: 
Autor: Paiola
*/
#include <bits/stdc++.h>

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 


int main()
{
	int m, n, i, x, v, y, soma = 0, melhor = 0;
	int saldos[1001];
	
	fastscan(m); fastscan(n);
	memset(saldos, 0, sizeof(saldos));
		
	for(i = 0; i < m; i++)
	{
		fastscan(x); fastscan(v); fastscan(y);
		saldos[x-1] -= v;
		saldos[y-1] += v;
		soma += v;
	}
	
	for(i = 0; i < n; i++)
		if (0 < saldos[i])
			melhor += saldos[i];
	
	printf("%c\n", (melhor < soma) ? 'S' : 'N');
	
	printf("%d\n", melhor);
}