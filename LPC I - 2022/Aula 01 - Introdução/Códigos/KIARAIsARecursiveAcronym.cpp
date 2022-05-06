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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> alpha(26);
    vector<string> w(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i];
        alpha[w[i][0] - 'A'] = true;
    }

    for (int i = 0; i < n; i++) {
        int j = 0;

        for (; j < w[i].size(); j++)
            if (!alpha[w[i][j] - 'A'])
                break;

        if (j == w[i].size()) {
            cout << "Y\n";
            return 0;
        }
    }

    cout << "N\n";

    return 0;
}
