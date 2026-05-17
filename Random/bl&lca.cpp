// ----------------------------- Binary Lifting & LCA -----------------------------
class TreeLCA {
public:
    ll n, LOG;
    vector<vll> up;
    vll depth;

    // Constructor: 1-indexed (sizes to n+1)
    TreeLCA(ll n) {
        this->n = n;
        this->LOG = 0;
        // Calculate the maximum power of 2 needed for N nodes
        while ((1LL << LOG) <= n) LOG++;
        
        // up[u][j] stores the 2^j-th ancestor of node u
        up.assign(n + 1, vll(LOG, 0));
        depth.assign(n + 1, 0);
    }

    /**
     * Precomputes the depth and binary lifting table.
     * Call this ONCE from your main solve() function: lca.dfs(root, 0, 0, adj);
     * * @param u      Current node
     * @param p      Parent of current node (use 0 for the root's parent)
     * @param d      Current depth
     * @param adj    The adjacency list of the tree
     */
    void dfs(ll u, ll p, ll d, const vector<vll>& adj) {
        depth[u] = d;
        up[u][0] = p; // The 2^0 (1st) ancestor is the direct parent

        // DP state transition: Build the 2^j th ancestors
        rep(j, 1, LOG) {
            if (up[u][j - 1] != 0) {
                up[u][j] = up[ up[u][j - 1] ][j - 1];
            } else {
                up[u][j] = 0; // If we jump past the root, the ancestor is 0
            }
        }

        // Standard DFS traversal
        for (ll v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }
    }

    /**
     * Finds the Lowest Common Ancestor of nodes u and v in O(log N) time.
     */
    ll get_lca(ll u, ll v) {
        // Step 1: Ensure u is the deeper node mathematically. If not, swap them.
        if (depth[u] < depth[v]) swap(u, v);

        // Step 2: Elevate u to the exact same depth as v
        ll k = depth[u] - depth[v];
        rep(j, 0, LOG) {
            // If the j-th bit of k is set, jump 2^j steps
            if ((k >> j) & 1) {
                u = up[u][j];
            }
        }

        // Step 3: If they are now the same node, we found the LCA
        if (u == v) return u;

        // Step 4: Lift both nodes simultaneously, stopping right BEFORE they match.
        // We iterate backwards from the largest possible jump down to 1.
        rev(j, LOG - 1, 0) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        // Step 5: They are now sitting exactly one level below the true LCA.
        return up[u][0];
    }

    /**
     * Bonus Tool: Get the k-th ancestor of node u in O(log N)
     * Extremely useful for tree routing problems. Returns 0 if ancestor doesn't exist.
     */
    ll get_kth_ancestor(ll u, ll k) {
        rep(j, 0, LOG) {
            if ((k >> j) & 1) {
                u = up[u][j];
                if (u == 0) return 0; // Prevent out-of-bounds if k is too large
            }
        }
        return u;
    }
    
    /**
     * Bonus Tool: Get the exact distance (number of edges) between u and v
     */
    ll get_distance(ll u, ll v) {
        ll lca = get_lca(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
};
// ====================================================================================
