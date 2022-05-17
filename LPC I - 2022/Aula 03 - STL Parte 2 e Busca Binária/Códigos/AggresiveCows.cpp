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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        ll n, c;
        cin >> n >> c;

        vector<ll> stall(n);

        for(int i = 0; i < n; i++)
            cin >> stall[i];

        sort(begin(stall), end(stall));

        ll left = 1, right = stall[n - 1], ma = 0;

        while(left <= right){
            ll mid = (left + right) / 2, cows = 1, pos = stall[0];
            
            for(int i = 1; i < n; i++){
                if(stall[i] - pos >= mid){
                    cows++;
                    pos = stall[i];
                }
            }

            if(cows >= c){
                ma = max(ma, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }

        cout << ma << "\n";
    }

    return 0;
}