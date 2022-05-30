#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    for (ll t = 1; t <= T; t++) {
        ll n;
        cin >> n;

        ll sum = 0, ans = 0;
        vi coins(n);

        for (ll i = 0; i < n; i++)
            cin >> coins[i];

        sort(begin(coins), end(coins));

        for (ll i = 0; i < n - 1; i++) {
            if(sum + coins[i] < coins[i + 1]) {
                sum += coins[i];
                ans++;
            }
        }

        if(n > 0)
            ans++;

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
