/*
Problema: Ada and Queue
Categorias:
	data structure
Dificuldade: facil
Descricao: 
Dica: cuidado com a operação reverse(), ela tem complexidade O(n)
Autor: Paiola
*/

#include<bits/stdc++.h>
    
using namespace std;
    
int main()
{
    int q, x;
    string op;
    deque<int> fila;
    bool inv = false;

    cin >> q;
    while(q--)
    {
        cin >> op;
        if (op == "back")
        {
            if (fila.empty())
                cout << "No job for Ada?" << endl;
            else if (inv)
            { 
                cout << fila.front() << endl;
                fila.pop_front();
            }
            else
            {
                cout << fila.back() << endl;
                fila.pop_back();
            }
        }
        else if (op == "front")
        {
            if (fila.empty())
                cout << "No job for Ada?" << endl;
            else if (inv)
            { 
                cout << fila.back() << endl;
                fila.pop_back();
            }
            else
            {
                cout << fila.front() << endl;
                fila.pop_front();
            }
        }
        else if (op == "reverse")
        {
            inv = !inv;
        }
        else if (op == "push_back")
        {
            cin >> x;
            if (inv)
                fila.push_front(x);
            else
                fila.push_back(x);
        }
        else //op == toFront
        {
            cin >> x;
            if (inv)
                fila.push_back(x);
            else
                fila.push_front(x);
        }
    }
} 