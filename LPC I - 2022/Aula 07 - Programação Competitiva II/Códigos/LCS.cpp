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

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size(), m = str2.size();
    vector<vi> dp(n + 1, vi(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    str2.clear();

    while (dp[i][j] != 0) {
        if (dp[i][j] > max(dp[i - 1][j], dp[i][j - 1])) {
            str2 += str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(str2.begin(), str2.end());
    cout << str2 << "\n";

    return 0;
}
