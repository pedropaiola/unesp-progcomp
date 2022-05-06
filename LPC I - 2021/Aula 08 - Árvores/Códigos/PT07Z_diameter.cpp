#include<bits/stdc++.h>
#define MAXN 10000

using namespace std;

vector<int> arvore[MAXN];
int height[MAXN];
int maxLenght[MAXN];
int diameter=0;

void aresta(int u, int v)
{
    arvore[u].push_back(v); 
    arvore[v].push_back(u);
}

int dfs(int u, int pai){
    height[u] = 1;
    int maxA = 0, maxB = 0;
    for(auto v: arvore[u]){
        if (v == pai)
            continue;
        height[u] = max(height[u], 1 + dfs(v, u));
        if (height[v] > maxA){
            maxB = maxA;
            maxA = height[v];
        } else if (height[v] > maxB)
            maxB = height[v];
    }
    maxLenght[u] = maxA + maxB;
    diameter = max(diameter, maxLenght[u]);
    return height[u];
}

int main(){
    int n, a, b;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        aresta(a-1, b-1);
    }
    dfs(0, -1);
    cout << diameter << endl;
}