#include <bits/stdc++.h>

#define MAX
#define MOD

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, h;
    cin >> t;

    while (t--) {
        cin >> n >> h;

        vector<ll> hit(n);

        for (int i = 0; i < n; i++)
            cin >> hit[i];

        ll mid, damage, l = 0, r = h, k = h;

        while (l <= r) {
            mid = (l + r) / 2; 
            damage = 0;

            for (ll i = 1; i < n; i++)
                damage += min(mid, hit[i] - hit[i - 1]);

            damage += mid;

            if (damage >= h) {
                k = min(k, mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }

        cout << k << "\n";
    }

    return 0;
}