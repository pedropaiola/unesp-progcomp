#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll combinatorial(int n, int k){
    k = min(k, n-k);
    if(k == 0)return 1;
    ll ans = n;
    for(int i = 2; i <= k ; i++)
        ans = (ans*(n-i+1))/i;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << combinatorial(n-1, k-1) << '\n';
    }
}