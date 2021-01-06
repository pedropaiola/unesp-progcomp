/*
Problema: GATTACA
Categorias:
	strings > suffix array
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

string T;
int N;
int ra[MAX_N], temp_ra[MAX_N];
int sa[MAX_N], temp_sa[MAX_N];
int c[MAX_N];

/* O(N) */
void counting_sort(int k) {
   int i, sum, maxi = max(300, N);
   memset(c, 0, sizeof c);
   for (i = 0; i < N; i++)
      c[i + k < N ? ra[i + k] : 0]++;
   for (i = sum = 0; i < maxi; i++) {
      int t = c[i];
      c[i] = sum;
      sum += t;
   }
   for (i = 0; i < N; i++)
      temp_sa[c[sa[i] + k < N ? ra[sa[i] + k] : 0]++] = sa[i];
   for (i = 0; i < N; i++)
      sa[i] = temp_sa[i];
}

/* O(N * log N) */
void build_sa() {
   int i, k, r;
   for (i = 0; i < N; i++)
      ra[i] = T[i];
   for (i = 0; i < N; i++)
      sa[i] = i;
   for (k = 1; k < N; k <<= 1) {
      counting_sort(k);
      counting_sort(0);
      temp_ra[sa[0]] = r = 0;
      for (i = 1; i < N; i++)
         temp_ra[sa[i]] =
             (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k]) ? r : ++r;
      for (i = 0; i < N; i++)
         ra[i] = temp_ra[i];
      if (ra[sa[N - 1]] == N - 1)
         break;
   }
}

vector<int> kasai()
{
    int n=T.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && T[i+k]==T[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}

int main(){
    int casos, maxMPC, posR, repeticoes;
    cin >> casos;

    while(casos--){
      cin >> T;
      T += '$';
      N = T.size();
      posR = N - 1;

      build_sa();
      vector<int> mpc = kasai();

      //for(int i = 0; i < N; i++){
      //   cout << i << ": " << sa[i] << " " << mpc[i] << " " << T.substr(sa[i]) << endl;
      //}

      for(int i = N - 2; i >= 0; i--){
         if (mpc[i] != 0 && mpc[posR] <= mpc[i])
            posR = i;
      }
      if (posR == N-1){
         cout << "No repetitions found!" << endl;
         continue;
      }
      repeticoes = 1;
      for(int i = posR; i < N; i++){
         if(mpc[posR] != mpc[i])
            break;
         repeticoes++;
      }
      cout << T.substr(sa[posR], mpc[posR]) << " " << repeticoes << endl;
    }
}
