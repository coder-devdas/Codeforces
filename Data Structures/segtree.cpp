/**
 * Algorithm: Segment Tree (Point Update, Range Query)
 * Time Complexity: O(N) build, O(log N) update/query
 * Prerequisites: template macros (ll, vll, sz, rep)
 * Note: 0-indexed array, 0-indexed queries. Change combine() for Min/Max/GCD.
 * 
 * Usage:
 * vll a = {1, 2, 3, 4, 5};
 * SegTree st(a);
 * st.update(2, 10); // Changes a[2] to 10
 * ll ans = st.query(1, 3); // Queries range [1, 3] inclusive
 */

struct SegTree {
    ll n;
    vll tree;
    const ll NEUTRAL = 0; // Change to INF for Min, -INF for Max

    SegTree(const vll& a) {
        n = sz(a);
        tree.assign(4 * n, NEUTRAL);
        build(a, 1, 0, n - 1);
    }

    ll combine(ll left, ll right) {
        return left + right; // Change to min(), max(), std::gcd() as needed
    }

    void build(const vll& a, ll node, ll tl, ll tr) {
        if (tl == tr) {
            tree[node] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, node * 2, tl, tm);
            build(a, node * 2 + 1, tm + 1, tr);
            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(ll node, ll tl, ll tr, ll pos, ll val) {
        if (tl == tr) {
            tree[node] = val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) update(node * 2, tl, tm, pos, val);
            else update(node * 2 + 1, tm + 1, tr, pos, val);
            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    ll query(ll node, ll tl, ll tr, ll l, ll r) {
        if (l > r) return NEUTRAL;
        if (l == tl && r == tr) return tree[node];
        ll tm = (tl + tr) / 2;
        return combine(query(node * 2, tl, tm, l, min(r, tm)),
                       query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    // Public wrappers
    void update(ll pos, ll val) { update(1, 0, n - 1, pos, val); }
    ll query(ll l, ll r) { return query(1, 0, n - 1, l, r); }
};
