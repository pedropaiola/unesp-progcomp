#include <bits/stdc++.h>

#define MAX 100000
#define MOD
#define INF 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

void set_io(string s) {
    if (!s.empty()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi coins;

    for (int i = 1; i * i <= MAX; i++)
        coins.push_back(i * i);

    int m = coins.size();
    vi dp(MAX + 1, INF + 1);
    dp[0] = 0;

    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}
