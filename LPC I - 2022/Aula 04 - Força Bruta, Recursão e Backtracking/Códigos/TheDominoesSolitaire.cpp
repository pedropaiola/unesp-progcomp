#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int n, m;
ii b, e;
vii piece;
vector<bool> used;

bool solve(int prev, int k){
    if(k == n)
        return prev == e.first;

    for(int i = 0; i < m; i++){
        if(!used[i]){
            int r, l;
            r = piece[i].first;
            l = piece[i].second;
            used[i] = true;

            if(r == prev){
                if(solve(l, k + 1))
                    return true;
            }
            
            if(l == prev){
                if(solve(r, k + 1))
                    return true;
            }
            
            used[i] = false;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> n){
        if(n == 0)
            break;

        cin >> m >> b.first >> b.second >> e.first >> e.second;

        piece = vii(m);
        used = vector<bool>(m);

        for(int i = 0; i < m; i++)
            cin >> piece[i].first >> piece[i].second;
    
        cout << (solve(b.second, 0) ? "YES\n" : "NO\n");
    }

    return 0;
}