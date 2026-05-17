/**
 * Algorithm: Disjoint Set Union (DSU)
 * Time Complexity: O(alpha(N)) ~ O(1) per operation
 * Prerequisites: template macros (ll, rep, all)
 * 
 * Usage:
 * DSU dsu(n); // 1-indexed safely up to n
 * dsu.unite(1, 2);
 * if (dsu.find(1) == dsu.find(2)) cout << "Connected!";
 * cout << dsu.get_size(1); // Size of component containing node 1
 * cout << dsu.components; // Total number of distinct components
 */

struct DSU {
    vector<ll> parent, sz;
    ll components;

    DSU(ll n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        components = n;
        iota(all(parent), 0);
    }

    ll find(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            components--;
            return true;
        }
        return false;
    }

    ll get_size(ll v) {
        return sz[find(v)];
    }
};
