/*
Problema: Rare Order
Categorias:
	graphs > topological sorting
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola 
*/
#include<bits/stdc++.h>
#define MAX_V 256
#define MAX_A 1000

using namespace std;

int grau[MAX_V];
int in_degree[MAX_V];

char adj[MAX_V][MAX_A];

void init(){
    memset(grau, 0, sizeof(grau));
    memset(in_degree, 0, sizeof(in_degree));
}

void aresta(char a, char b){
    adj[a][grau[a]] = b;
    grau[a]++;
    in_degree[b]++;
}

string L;
void topological_sort(){
    queue<char> z;
    char v, w;
    L = "";
    for(char c = 'A'; c <= 'Z'; c++){
        if (grau[c] == 0)
            continue;
        if (in_degree[c] == 0)
            z.push(c);
    }
    while(!z.empty()){
        v = z.front(); z.pop();
        L += v;
        for(int i = 0; i < grau[v]; i++){
            w = adj[v][i];
            in_degree[w]--;
            if(!in_degree[w])
                z.push(w);
        }
    }
}

int main()
{
    int tam1, tam2, k;
    string s1, s2;

    while(cin >> s1)
    {
        if (cin.eof()) break;
        init();
        while(s1 != "#"){
            cin >> s2;
            if (s2 == "#")
                break;
            tam1 = s1.size();
            tam2 = s2.size();
            k = 0;
            while (k < tam1 && k < tam2 && s1[k] == s2[k])
                k++;
            if (k == tam1){
                s1 = s2;
                continue;
            }
            aresta(s1[k], s2[k]);
            s1 = s2;
        }
        topological_sort();
        cout << L << endl;    
    }
}