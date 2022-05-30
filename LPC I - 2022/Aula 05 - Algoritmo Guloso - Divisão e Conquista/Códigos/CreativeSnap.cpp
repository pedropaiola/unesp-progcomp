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

ll A, B;
vi arr;

ll solve(ll left, ll right) {
    ll n = upper_bound(begin(arr), end(arr), right) - lower_bound(begin(arr), end(arr), left);

    if (left == right)
        return n ? n * B : A;
    else if (n == 0)
        return A;

    ll mid, sum, l, r, len;
    mid = (left + right) >> 1;
    len = right - left + 1;
    sum = n * B * len;
    l = solve(left, mid);
    r = solve(mid + 1, right);

    return min(sum, l + r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, len;
    cin >> n >> k >> A >> B;
    len = 1 << n;
    arr = vi(k);

    for (ll i = 0; i < k; i++)
        cin >> arr[i];

    sort(begin(arr), end(arr));

    cout << solve(1, len) << "\n";

    return 0;
}
