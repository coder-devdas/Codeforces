// ----------------------------- Kruskal's MST Engine -----------------------------

// Explicit structure representing a single weighted graph edge
struct Edge {
    ll u, v, weight, id; // 'id' stores the original index of the edge

    // Custom strict-weak ordering operator
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

/**
 * Computes the MST and actively builds the resulting tree structure in memory.
 * * @param n           The total number of vertices (nodes) in the graph.
 * @param edges       A flat vector list containing all edges in the graph.
 * @param mst_adj     (Output) Adjacency list of the MST. Stores {neighbor, weight}.
 * @param mst_edges   (Output) A flat list of the exact Edge structs that formed the MST.
 * @return            The total minimum weight of the tree. Returns -1 if disconnected.
 */
ll kruskals_mst(ll n, vector<Edge>& edges, vector<vector<pll>>& mst_adj, vector<Edge>& mst_edges) {
    // 1. Sort all edges in non-decreasing order of their weights
    sort(all(edges));

    // 2. Initialize our optimized DSU engine
    DSU dsu(n);

    ll total_mst_weight = 0;
    ll edges_added = 0;

    // 3. Clear and size the output containers to guarantee a clean slate
    mst_adj.assign(n + 1, vector<pll>());
    mst_edges.clear();

    // 4. Process every edge greedily
    rep(i, 0, sz(edges)) {
        if (dsu.union_sets(edges[i].u, edges[i].v)) {
            total_mst_weight += edges[i].weight;
            edges_added++;

            // --- THE UPGRADE: STORE THE TREE ---
            // A. Store the edge in our flat list for easy iteration later
            mst_edges.pb(edges[i]);

            // B. Build the bidirectional Adjacency List for DFS/LCA traversal
            mst_adj[edges[i].u].pb({edges[i].v, edges[i].weight});
            mst_adj[edges[i].v].pb({edges[i].u, edges[i].weight});
            // -----------------------------------

            if (edges_added == n - 1) {
                break;
            }
        }
    }

    // 5. Structural Edge Case Validation
    if (edges_added != n - 1) {
        return -1; // Graph is disconnected
    }

    return total_mst_weight;
}
// ====================================================================================
