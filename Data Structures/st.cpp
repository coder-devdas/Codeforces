/**
 * Algorithm: Sparse Table (Range Minimum/Maximum/GCD Query)
 * Time Complexity: O(N log N) build, O(1) query
 * Prerequisites: template macros (ll, rep, sz), static array (NO UPDATES)
 * Note: Currently set up for MINIMUM. Change the min() in build/query for MAX or GCD.
 * 
 * Usage:
 * vector<ll> a = {1, 5, 2, 4, 3};
 * SparseTable st(a);
 * ll ans = st.query(1, 3); // Minimum from index 1 to 3 (0-indexed)
 */

struct SparseTable {
    ll n, K;
    vector<vector<ll>> st;

    SparseTable(const vector<ll>& a) {
        n = sz(a);
        K = __lg(n) + 1;
        st.assign(K, vector<ll>(n));
        rep(i, 0, n) st[0][i] = a[i];
        
        rep(i, 1, K) {
            rep(j, 0, n - (1 << i) + 1) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    ll query(ll L, ll R) {
        if (L > R) return INF; // Return appropriate neutral element
        ll i = __lg(R - L + 1);
        return min(st[i][L], st[i][R - (1 << i) + 1]);
    }
};
