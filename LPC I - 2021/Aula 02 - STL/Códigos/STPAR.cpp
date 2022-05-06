/*
Problema: Street Parade
Categorias:
	data structure > queue
    data structure > stack
Dificuldade: facil
Descricao: 
Dica: 
Autor: Paiola
*/

#include<bits/stdc++.h>
    
using namespace std;
    
int main()
{
    int n, i, x;
    while(1)
    {
        cin >> n;
        if (n == 0)
            break;
            
        queue<int> fila;
        stack<int> pilhaMenores, pilhaMaiores;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            fila.push(x);
        }
        
        pilhaMenores.push(0);
        while(!fila.empty())
        {
            if (fila.front() == (pilhaMenores.top() + 1))
            {
                pilhaMenores.push(fila.front());
                fila.pop();
            }
            else
            {
                if (pilhaMaiores.empty())
                {
                    pilhaMaiores.push(fila.front());
                    fila.pop();
                }
                else
                {
                    while(!pilhaMaiores.empty() && (pilhaMaiores.top() == (pilhaMenores.top() + 1)))
                    {
                        pilhaMenores.push(pilhaMaiores.top());
                        pilhaMaiores.pop();
                    }
                    
                    if (fila.front() == (pilhaMenores.top() + 1))
                    {
                        pilhaMenores.push(fila.front());
                        fila.pop();
                    }
                    else
                    {
                        pilhaMaiores.push(fila.front());
                        fila.pop();
                    }
                }
            }	
        }
        while(!pilhaMaiores.empty() && (pilhaMaiores.top() == (pilhaMenores.top() + 1)))
        {
            pilhaMenores.push(pilhaMaiores.top());
            pilhaMaiores.pop();
        }
        cout << ((fila.empty() && pilhaMaiores.empty()) ? "yes" : "no") << endl;
    }
} 