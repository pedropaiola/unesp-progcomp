/*
Problema: Running Median Again
Categorias:
    data structure > priority queue
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, n;
    cin >> t;
    while(t--){
        priority_queue<int> esq, dir;
        int med = 0;
        while(1){
            cin >> n;
            if (n == 0)
                break;
            if (n > 0)
            {
                if (n > med)
                    dir.push(-n);
                else
                    esq.push(n);

                if ((esq.size() - dir.size()) == 2)
                {
                    dir.push(-esq.top());
                    esq.pop();
                }       
                else if ((dir.size() - esq.size()) == 2)
                {
                    esq.push(-dir.top());
                    dir.pop();
                }     
            }           
            else
            {
                cout << med << "\n";
                if (esq.size() < dir.size())
                    dir.pop();
                else
                    esq.pop();
            }
            if (esq.empty() && dir.empty())
                med = 0;
            else if (esq.size() < dir.size())
                med = -dir.top();
            else
                med = esq.top();
        }
    }
}