#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF
#define EPSILON
#define PI 3.14159265359

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

struct node {
    ll mi;

    node(const ll &mi = LONG_LONG_MAX) {
        this->mi = mi;
    }
};

vi arr;
vector<node> st;

node merge(const node &l, const node &r) {
    return node(min(l.mi, r.mi));
}

void build(ll idx, ll begin, ll end) {
    if (begin == end) {
        st[idx] = node(arr[begin]);
        return;
    }

    ll mid, l, r;
    mid = (begin + end) >> 1;
    l = idx * 2;
    r = idx * 2 + 1;

    build(l, begin, mid);
    build(r, mid + 1, end);

    st[idx] = merge(st[l], st[r]);
}

void update(ll idx, ll begin, ll end, const ll &pos, const ll &val) {
    if (begin == end) {
        st[idx] = node(val);
        return;
    }

    ll mid, l, r;
    mid = (begin + end) >> 1;
    l = idx * 2;
    r = idx * 2 + 1;

    if (pos <= mid)
        update(l, begin, mid, pos, val);
    else
        update(r, mid + 1, end, pos, val);

    st[idx] = merge(st[l], st[r]);
}

node query(ll idx, ll begin, ll end, const ll &left, const ll &right) {
    if (left <= begin && end <= right)
        return st[idx];
    else if (left > end || right < begin)
        return node();

    ll mid, l, r;
    mid = (begin + end) >> 1;
    l = idx * 2;
    r = idx * 2 + 1;

    node q1, q2;
    q1 = query(l, begin, mid, left, right);
    q2 = query(r, mid + 1, end, left, right);

    return merge(q1, q2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    arr = vi(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    st = vector<node>(4 * n + 1);

    build(1, 1, n);

    while (q--) {
        ll op;
        cin >> op;

        if (op == 1) {
            ll k, u;
            cin >> k >> u;

            update(1, 1, n, k, u);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).mi << "\n";
        }
    }

    return 0;
}
