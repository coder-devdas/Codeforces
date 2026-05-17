/**
 * Algorithm: Lazy Segment Tree (Range Update, Range Sum)
 * Time Complexity: O(log N) for both range update and range query
 * Prerequisites: template macros (ll, vll, sz)
 * Note: 0-indexed. This template is specifically for Range ADD and Range SUM.
 * 
 * Usage:
 * LazySegTree st(n);
 * st.update(1, 3, 5); // Adds 5 to all elements in range [1, 3]
 * ll total = st.query(0, 4); // Sum of range [0, 4]
 */

struct LazySegTree {
    ll n;
    vll tree, lazy;

    LazySegTree(ll _n) {
        n = _n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(ll node, ll tl, ll tr) {
        if (lazy[node] != 0) {
            ll tm = (tl + tr) / 2;
            lazy[node * 2] += lazy[node];
            tree[node * 2] += lazy[node] * (tm - tl + 1);
            lazy[node * 2 + 1] += lazy[node];
            tree[node * 2 + 1] += lazy[node] * (tr - tm);
            lazy[node] = 0;
        }
    }

    void update(ll node, ll tl, ll tr, ll l, ll r, ll addend) {
        if (l > r) return;
        if (l == tl && tr == r) {
            tree[node] += addend * (tr - tl + 1);
            lazy[node] += addend;
        } else {
            push(node, tl, tr);
            ll tm = (tl + tr) / 2;
            update(node * 2, tl, tm, l, min(r, tm), addend);
            update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    ll query(ll node, ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        if (l == tl && tr == r) return tree[node];
        push(node, tl, tr);
        ll tm = (tl + tr) / 2;
        return query(node * 2, tl, tm, l, min(r, tm)) + 
               query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    // Public wrappers
    void update(ll l, ll r, ll val) { update(1, 0, n - 1, l, r, val); }
    ll query(ll l, ll r) { return query(1, 0, n - 1, l, r); }
};
