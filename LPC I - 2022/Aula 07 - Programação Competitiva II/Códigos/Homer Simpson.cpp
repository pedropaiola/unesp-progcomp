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

    int t, n, m;

    while (cin >> m >> n >> t) {
        vi dp(t + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= t; i++) {
            if (i - n >= 0 && dp[i - n] != -1)
                dp[i] = max(dp[i], dp[i - n] + 1);

            if (i - m >= 0 && dp[i - m] != -1)
                dp[i] = max(dp[i], dp[i - m] + 1);
        }

        int T = t;

        while(dp[T] == -1)
            T--;
        
        cout << dp[T];

        if(T != t)
            cout << " " << t - T;

        cout << "\n";
    }

    return 0;
}
