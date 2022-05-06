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

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, i, player = 0;
        cin >> a >> b >> c;

        vi pos(a, 1);
        map<int, int> shortcut;

        for (i = 0; i < b; i++) {
            int at, to;
            cin >> at >> to;
            shortcut.insert({at, to});
        }

        for (i = 0; i < c; i++) {
            int roll;
            cin >> roll;
            pos[player] += roll;

            if (shortcut.count(pos[player]))
                pos[player] = shortcut[pos[player]];

            if (pos[player] >= 100) {
                pos[player] = 100;
                break;
            }

            player = (player + 1) % a;
        }

        for (i = i + 1; i < c; i++) {
            int roll;
            cin >> roll;
        }

        for (i = 0; i < a; i++)
            cout << "Position of player " << i + 1 << " is " << pos[i] << ".\n";
    }

    return 0;
}
