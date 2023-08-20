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
    ll sum, lazy;

    node(const ll &sum = 0) {
        this->sum = sum;
        lazy = 0;
    }
};

vector<node> st;

node merge(const node &l, const node &r) {
    return node(l.sum + r.sum);
}

void build(ll idx, ll begin, ll end) {
    if (begin == end) {
        st[idx] = node();
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

void propagate(const ll &idx, const ll &begin, const ll &end) {
    if (st[idx].lazy == 0)
        return;

    st[idx].sum += (end - begin + 1) * st[idx].lazy;

    if (begin != end) {
        int l = 2 * idx;
        int r = 2 * idx + 1;

        st[l].lazy += st[idx].lazy;
        st[r].lazy += st[idx].lazy;
    }

    st[idx].lazy = 0;

    return;
}

void update(ll idx, ll begin, ll end, const ll &left, const ll &right, const ll &val) {
    propagate(idx, begin, end);

    if (left <= begin && end <= right) {
        st[idx].lazy += val;
        propagate(idx, begin, end);
        return;
    } else if (left > end || right < begin)
        return;

    ll mid, l, r;
    mid = (begin + end) >> 1;
    l = idx * 2;
    r = idx * 2 + 1;

    update(l, begin, mid, left, right, val);
    update(r, mid + 1, end, left, right, val);

    st[idx] = merge(st[l], st[r]);
}

node query(ll idx, ll begin, ll end, const ll &left, const ll &right) {
    propagate(idx, begin, end);

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

    ll t;
    cin >> t;

    while (t--) {
        ll n, c;
        cin >> n >> c;

        st = vector<node>(4 * n + 1);

        build(1, 1, n);

        while (c--) {
            ll op, l, r;
            cin >> op >> l >> r;

            if (op == 0) {
                ll v;
                cin >> v;
                update(1, 1, n, l, r, v);
            } else {
                ll sum;
                sum = query(1, 1, n, l, r).sum;
                cout << sum << "\n";
            }
        }
    }

    return 0;
}
