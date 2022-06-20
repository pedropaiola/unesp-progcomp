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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vi dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i - a >= 0 && dp[i - a] != -1)
            dp[i] = max(dp[i], dp[i - a] + 1);

        if (i - b >= 0 && dp[i - b] != -1)
            dp[i] = max(dp[i], dp[i - b] + 1);

        if (i - c >= 0 && dp[i - c] != -1)
            dp[i] = max(dp[i], dp[i - c] + 1);
    }

    cout << dp[n] << "\n";

    return 0;
}
