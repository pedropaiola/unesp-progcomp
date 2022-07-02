#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i, j;
    int mat[10][10];
    bool apareceu[101];
    int num_faltante, lin, col;
    memset(apareceu, false, sizeof(apareceu));
    
    cin >> n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 0)
            {
                lin = i+1;
                col = j+1;
            }
            else
                apareceu[mat[i][j]] = true;
        }
    }

    for(i = 1; i <= n*n; i++){
        if (!apareceu[i])
        {
            num_faltante = i;
            break;
        }
    }
    cout << num_faltante << "\n" << lin << "\n" << col << "\n";
}