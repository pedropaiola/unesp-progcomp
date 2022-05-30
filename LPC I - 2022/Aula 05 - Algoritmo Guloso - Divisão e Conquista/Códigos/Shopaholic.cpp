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

bool cmp(const int &a, const int &b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(begin(arr), end(arr), cmp);

        int discount = 0;

        for (int i = 2; i < n; i += 3)
            discount += arr[i];

        cout << discount << "\n";
    }

    return 0;
}
