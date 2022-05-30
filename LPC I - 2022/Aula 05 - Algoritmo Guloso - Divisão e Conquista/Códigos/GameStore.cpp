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

bool cmp(const tuple<int, int, int, int> &a, const tuple<int, int, int, int> &b) {
    int h1, e1, a1, idx1;
    int h2, e2, a2, idx2;
    tie(h1, e1, a1, idx1) = a;
    tie(h2, e2, a2, idx2) = b;

    if(h1 == h2){
        if(e1 == e2)
            return a1 > a2;

        return e1 < e2;
    }

    return h1 > h2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> levels(n);

    for(int i = 0; i < n; i++){
        int h, e, a;
        cin >> h >> e >> a;
        levels[i] = {h, e, a, i + 1};
    }

    sort(begin(levels), end(levels), cmp);

    int h1, e1, a1, idx1;
    int h2, e2, a2, idx2;
    tie(h1, e1, a1, idx1) = levels.front();
    tie(h2, e2, a2, idx2) = levels.back();

    if(idx1 != idx2){
        cout << "Easiest is level " << idx1 << "\n";
        cout << "Hardest is level " << idx2 << "\n";
    } else
        cout << "Easiest and Hardest is level " << idx1 << "\n";

    return 0;
}
