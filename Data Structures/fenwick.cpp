/**
 * Algorithm: Fenwick Tree (Binary Indexed Tree)
 * Time Complexity: O(log N) for both update and query
 * Prerequisites: template macros (ll)
 * Note: THIS IS STRICTLY 1-INDEXED. Never pass index 0 to add() or query().
 * 
 * Usage:
 * Fenwick bit(n);
 * bit.add(3, 10); // Adds 10 to index 3
 * ll sum = bit.query(2, 5); // Gets sum in range [2, 5]
 */

struct Fenwick {
    ll n;
    vector<ll> tree;

    Fenwick(ll _n) {
        n = _n;
        tree.assign(n + 1, 0);
    }

    void add(ll i, ll delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    ll query(ll i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    ll query(ll l, ll r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
