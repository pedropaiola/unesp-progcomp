/*
Problema: Creative Snap 
Categorias:
    divide and conquer
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
    
using namespace std;
    
vector<long long> posAvenger;
long long A, B;
    
long long resolve(long long e, long long d)
{
    long long i = lower_bound(posAvenger.begin(), posAvenger.end(), e) - posAvenger.begin(); //posição do primeiro vingador, se tiver no intervalo
    long long j = upper_bound(posAvenger.begin(), posAvenger.end(), d) - posAvenger.begin(); //posição do ultimo vingador
    j--;
    
    long long qtdeAvengers = j - i + 1;
    long long poder;
    
    if (qtdeAvengers == 0)
        poder = A;
    else
        poder = B*qtdeAvengers*(d-e+1);
        
    if (e == d || qtdeAvengers == 0)
        return poder;
        
    long long m = (e + d)/2;
    
    return min(poder, resolve(e, m) + resolve(m+1, d));
}
    
int main()
{
    long long n, k, i, x;
    cin >> n >> k >> A >> B;
    for(i = 0; i < k; i++)
    {
        cin >> x;
        posAvenger.push_back(x);
    }
    sort(posAvenger.begin(), posAvenger.end());
    long long d = (long long) 1 << n;
    cout << resolve(1, d) << endl;
}