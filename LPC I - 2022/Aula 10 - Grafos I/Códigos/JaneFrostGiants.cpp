#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF 1e7

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

int r, c;
vii dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vi> dist;
vector<string> grid;

int bfs(const vii &sources, bool jane) {
    int minutes = INF;
    queue<ii> q;

    for (auto [i, j] : sources) {
        dist[i][j] = 0;
        q.push({i, j});
    }

    while (!q.empty()) {
        int i, j;
        tie(i, j) = q.front();
        q.pop();

        if (jane && (i == 0 || i == r - 1 || j == 0 || j == c - 1))
            minutes = min(dist[i][j], minutes);

        for (auto [x, y] : dir) {
            int a, b;
            a = i + x;
            b = j + y;

            if (a >= 0 && a < r && b >= 0 && b < c && grid[a][b] == '.' && dist[i][j] + 1 < dist[a][b]) {
                dist[a][b] = dist[i][j] + 1;
                q.push({a, b});
            }
        }
    }

    return minutes;
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> r >> c;

        grid = vector<string>(r + 1);

        for (int i = 0; i < r; i++)
            cin >> grid[i];

        vii fire, jane;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'F')
                    fire.push_back({i, j});
                else if (grid[i][j] == 'J')
                    jane.push_back({i, j});
            }
        }

        int minutes;
        dist = vector<vi>(r + 1, vi(c + 1, INF));

        bfs(fire, false);
        minutes = bfs(jane, true);

        cout << "Case " << t << ": ";

        if (minutes != INF)
            cout << minutes + 1 << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}