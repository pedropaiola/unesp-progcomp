#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define N 101
#define W 100001
#define INF 999999999


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, w;
    cin >> n >> w;
    vector <pair<long long,long long>> v (n);
    long long dp[N][W] = {0};
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(v[i-1].first <= j)dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].first] + v[i-1].second);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][w] << endl;
}