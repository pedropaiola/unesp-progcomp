/*
Problema: Weird Points
Categorias:
	data structure > bit
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/

#include<bits/stdc++.h>
#define Point pair<int, int>
#define x first
#define y second
#define MAXN 100000

using namespace std;

bool comp(const Point &a, const Point &b){
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int getSum(int BITree[], int index) 
{ 
    int sum = 0;
    while (index > 0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    while (index <= n) 
    { 
       BITree[index] += val; 
       index += index & (-index); 
    } 
} 

void convert(int arr[], int n) 
{ 
    int temp[n]; 
    for (int i=0; i<n; i++) 
        temp[i] = arr[i]; 
    sort(temp, temp+n); 
  
    for (int i=0; i<n; i++) 
    { 
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1; 
    } 
} 

int main(){
    int t, n, k, i;
    cin >> t;
    while(t--){
        cin >> n >> k;

        int xaux[n], yaux[n], BIT[n+1];
        vector<Point> pontos;
        for(i = 0; i < n; i++){
            cin >> xaux[i] >> yaux[i];
            BIT[i+1] = 0;
        }
        convert(xaux, n);
        convert(yaux, n);
        for(i = 0; i < n; i++)
            pontos.push_back({xaux[i], yaux[i]});
        sort(pontos.begin(), pontos.end(), comp);
        //Com os pontos ordenados a partir de x, basta ver
        //para cada ponto pi quantos pontos pj existem tal que pj.y <= pi.y
        int cont = 0;
        int qtdeDom;
        for(i = 0; i < n; i++){
            //Vendo quantos pontos são dominados por pontos[i]
            //Para isso consultaremos a BIT (que armazena os ys que já passaram)
            qtdeDom = getSum(BIT, pontos[i].y);
            //cout << "Ponto (" << pontos[i].x << ", " << pontos[i].y << "): " << qtdeDom << endl; 
            if (abs(qtdeDom - (n - qtdeDom - 1)) >= k)
                cont++;
            updateBIT(BIT, n, pontos[i].y, 1); //Soma uma ocorrência de y
        }
        cout << cont << endl;
    }
}