#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef vector <int> vec;
typedef vector <pa> vep;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> v(n+1, INT_MAX);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    vector <int> dp(n+1, INT_MAX);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k && j < i; j++){
            dp[i] = min(dp[i], dp[i-j] + abs(v[i]-v[i-j]));
        }
    }
    cout << dp[n] << "\n";

    
    
}