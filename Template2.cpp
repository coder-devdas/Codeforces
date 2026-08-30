// Author: Coder Devdas
#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

// ----------------------------- Aliases -----------------------------
using ll  = long long;
using ld  = long double;

using pll  = pair<ll, ll>;
using vll  = vector<ll>;
using vpll = vector<pll>;

using vvll = vector<vll>;
using vvpll = vector<vpll>;

// ----------------------------- Macros -----------------------------
#define pb          push_back
#define mp          make_pair
#define ff          first
#define ss          second
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define sz(x)       ((ll)(x).size())

#define fr(i,a,b)   for (ll i = (a); i < (b); ++i)
#define rf(i,a,b)   for (ll i = (a); i >= (b); --i)
#define rep(i,a,b)  for (ll i = (a); i < (b); ++i)
#define rev(i,a,b)  for (ll i = (a); i >= (b); --i)
#define each(x,a)   for (auto& x : a)

#define endl '\n'

// ----------------------------- Constants -----------------------------
const ll MOD = 1000000007LL;
const ll INF = 4000000000000000000LL;
const ld EPS = 1e-12;

// ----------------------------- Input Shortcuts -----------------------------
template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
    return in >> p.ff >> p.ss;
}

template<typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto &x : v) in >> x;
    return in;
}

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename T>
void ivec(ll n, vector<T>& v) {
    v.resize(n);
    for (auto &x : v) cin >> x;
}

// ----------------------------- Output Shortcuts -----------------------------
template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
    return out << p.ff << " " << p.ss;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (ll i = 0; i < sz(v); ++i)
        out << v[i] << (i + 1 == sz(v) ? "" : " ");
    return out;
}

template<typename T, typename... Args>
void print(T&& first, Args&&... args) {
    cout << first;
    ((cout << " " << forward<Args>(args)), ...);
}

template<typename... Args>
void println(Args&&... args) {
    if constexpr (sizeof...(args) > 0)
        print(forward<Args>(args)...);
    cout << '\n';
}

void YES(bool t = true) {
    cout << (t ? "YES\n" : "NO\n");
}

void Yes(bool t = true) {
    cout << (t ? "Yes\n" : "No\n");
}

// ----------------------------- Debugging -----------------------------
void _print(ll t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(bool t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);

template <class T>
void _print(vector<T> v);

template <class T>
void _print(set<T> v);

template <class T, class V>
void _print(map<T, V> v);

template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}

template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

// ----------------------------- Fast I/O -----------------------------
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ================================================================
//                         BASIC MATH
// ================================================================

ll ceil_div(ll a, ll b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

ll floor_div(ll a, ll b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}

ll mod(ll a, ll m = MOD) {
    return (a % m + m) % m;
}

ll modpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;

    while (b) {
        if (b & 1) res = (__int128)res * a % m;
        a = (__int128)a * a % m;
        b >>= 1;
    }

    return res;
}

ll modinv(ll a, ll m = MOD) {
    return modpow(a, m - 2, m);
}

ll gcdll(ll a, ll b) {
    return __gcd(a, b);
}

ll lcmll(ll a, ll b) {
    return a / gcdll(a, b) * b;
}

ll power(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

ll xor_upto(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// ================================================================
//                         NUMBER THEORY
// ================================================================

// ---------- Sieve ----------
vll sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    vll primes;

    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (ll i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;

        primes.pb(i);

        if (i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return primes;
}

// ---------- SPF ----------
vll build_spf(ll n) {
    vll spf(n + 1);

    iota(all(spf), 0);

    if (n >= 1) spf[1] = 1;

    for (ll i = 2; i * i <= n; ++i) {
        if (spf[i] != i) continue;

        for (ll j = i * i; j <= n; j += i) {
            if (spf[j] == j)
                spf[j] = i;
        }
    }

    return spf;
}

// ---------- Prime Factorization ----------
vpll factorize(ll n) {
    vpll factors;

    for (ll p = 2; p * p <= n; ++p) {
        if (n % p) continue;

        ll cnt = 0;

        while (n % p == 0) {
            n /= p;
            ++cnt;
        }

        factors.pb({p, cnt});
    }

    if (n > 1)
        factors.pb({n, 1});

    return factors;
}

// ---------- Divisors ----------
vll divisors(ll n) {
    vll d;

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i) continue;

        d.pb(i);

        if (i * i != n)
            d.pb(n / i);
    }

    sort(all(d));
    return d;
}

// ---------- Euler Phi ----------
ll phi(ll n) {
    ll ans = n;

    for (ll p = 2; p * p <= n; ++p) {
        if (n % p) continue;

        while (n % p == 0)
            n /= p;

        ans -= ans / p;
    }

    if (n > 1)
        ans -= ans / n;

    return ans;
}

// ================================================================
//                         COMBINATORICS
// ================================================================

struct Comb {
    ll n;
    vll fact, ifact;

    Comb(ll n) : n(n) {
        fact.resize(n + 1);
        ifact.resize(n + 1);

        fact[0] = 1;

        for (ll i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        ifact[n] = modinv(fact[n]);

        for (ll i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i % MOD;
    }

    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;

        return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
    }

    ll nPr(ll n, ll r) {
        if (r < 0 || r > n) return 0;

        return fact[n] * ifact[n - r] % MOD;
    }
};

// ================================================================
//                         PREFIX SUM
// ================================================================

vll prefix_sum(const vll& a) {
    ll n = sz(a);
    vll pref(n + 1, 0);

    for (ll i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];

    return pref;
}

// pref[r + 1] - pref[l]

vvll prefix_sum_2d(const vvll& a) {
    ll n = sz(a);
    ll m = sz(a[0]);

    vvll pref(n + 1, vll(m + 1, 0));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            pref[i + 1][j + 1] =
                a[i][j]
                + pref[i][j + 1]
                + pref[i + 1][j]
                - pref[i][j];
        }
    }

    return pref;
}

// ================================================================
//                    COORDINATE COMPRESSION
// ================================================================

vll compress(vll a) {
    vll b = a;

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (auto &x : a)
        x = lower_bound(all(b), x) - b.begin();

    return a;
}

// ================================================================
//                         FENWICK TREE
// ================================================================

struct Fenwick {
    ll n;
    vll bit;

    Fenwick(ll n = 0) {
        init(n);
    }

    void init(ll n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(ll idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll sum(ll idx) {
        ll res = 0;

        for (++idx; idx > 0; idx -= idx & -idx)
            res += bit[idx];

        return res;
    }

    ll query(ll l, ll r) {
        if (l > r) return 0;

        return sum(r) - (l ? sum(l - 1) : 0);
    }

    ll kth(ll k) {
        ll idx = 0;

        for (ll pw = 1LL << (__lg(n)); pw; pw >>= 1) {
            ll nxt = idx + pw;

            if (nxt <= n && bit[nxt] < k) {
                idx = nxt;
                k -= bit[nxt];
            }
        }

        return idx;
    }
};

// ================================================================
//                       SEGMENT TREE
// ================================================================

struct SegTree {
    ll n;
    vll tree;

    SegTree(ll n = 0) {
        init(n);
    }

    void init(ll n_) {
        n = n_;
        tree.assign(4 * n + 5, 0);
    }

    void build(ll node, ll l, ll r, const vll& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void build(const vll& a) {
        n = sz(a);
        tree.assign(4 * n + 5, 0);

        if (n)
            build(1, 0, n - 1, a);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        ll mid = (l + r) >> 1;

        if (idx <= mid)
            update(node << 1, l, mid, idx, val);
        else
            update(node << 1 | 1, mid + 1, r, idx, val);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void update(ll idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        ll mid = (l + r) >> 1;
        ll ans = 0;

        if (ql <= mid)
            ans += query(node << 1, l, mid, ql, qr);

        if (qr > mid)
            ans += query(node << 1 | 1, mid + 1, r, ql, qr);

        return ans;
    }

    ll query(ll l, ll r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

// ================================================================
//                     LAZY SEGMENT TREE
//              Range Add + Range Sum
// ================================================================

struct LazySegTree {
    ll n;
    vll tree, lazy;

    LazySegTree(ll n = 0) {
        init(n);
    }

    void init(ll n_) {
        n = n_;
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    void build(ll node, ll l, ll r, const vll& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void build(const vll& a) {
        n = sz(a);
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);

        if (n)
            build(1, 0, n - 1, a);
    }

    void apply(ll node, ll l, ll r, ll val) {
        tree[node] += (r - l + 1) * val;
        lazy[node] += val;
    }

    void push(ll node, ll l, ll r) {
        if (!lazy[node] || l == r)
            return;

        ll mid = (l + r) >> 1;

        apply(node << 1, l, mid, lazy[node]);
        apply(node << 1 | 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(ll node, ll l, ll r, ll ql, ll qr, ll val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        ll mid = (l + r) >> 1;

        if (ql <= mid)
            update(node << 1, l, mid, ql, qr, val);

        if (qr > mid)
            update(node << 1 | 1, mid + 1, r, ql, qr, val);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void update(ll l, ll r, ll val) {
        update(1, 0, n - 1, l, r, val);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        push(node, l, r);

        ll mid = (l + r) >> 1;
        ll ans = 0;

        if (ql <= mid)
            ans += query(node << 1, l, mid, ql, qr);

        if (qr > mid)
            ans += query(node << 1 | 1, mid + 1, r, ql, qr);

        return ans;
    }

    ll query(ll l, ll r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

// ================================================================
//                            DSU
// ================================================================

struct DSU {
    ll n;
    vll parent, sz;

    DSU(ll n = 0) {
        init(n);
    }

    void init(ll n_) {
        n = n_;
        parent.resize(n);
        sz.assign(n, 1);

        iota(all(parent), 0);
    }

    ll find(ll x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    ll size(ll x) {
        return sz[find(x)];
    }
};

// ================================================================
//                      GRAPH SHORTCUTS
// ================================================================

using Graph = vector<vll>;
using WGraph = vector<vpll>;

// ---------- BFS ----------
vll bfs(const Graph& g, ll src) {
    ll n = sz(g);

    vll dist(n, -1);
    queue<ll> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : g[u]) {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}

// ---------- DFS ----------
void dfs(ll u, ll p, const Graph& g, vll& vis) {
    vis[u] = 1;

    for (ll v : g[u]) {
        if (v == p)
            continue;

        if (!vis[v])
            dfs(v, u, g, vis);
    }
}

// ---------- Dijkstra ----------
vll dijkstra(const WGraph& g, ll src) {
    ll n = sz(g);

    vll dist(n, INF);

    priority_queue<
        pll,
        vector<pll>,
        greater<pll>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// ---------- 0-1 BFS ----------
vll zero_one_bfs(const WGraph& g, ll src) {
    ll n = sz(g);

    vll dist(n, INF);
    deque<ll> dq;

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty()) {
        ll u = dq.front();
        dq.pop_front();

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }

    return dist;
}

// ---------- Topological Sort ----------
vll topo_sort(const Graph& g) {
    ll n = sz(g);
    vll indeg(n, 0);

    for (ll u = 0; u < n; ++u)
        for (ll v : g[u])
            ++indeg[v];

    queue<ll> q;

    for (ll i = 0; i < n; ++i)
        if (indeg[i] == 0)
            q.push(i);

    vll order;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        order.pb(u);

        for (ll v : g[u]) {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    return order;
}

// ================================================================
//                         TREE / LCA
// ================================================================

struct LCA {
    ll n, LOG;
    Graph g;
    vvll up;
    vll depth;

    LCA(ll n = 0) {
        init(n);
    }

    void init(ll n_) {
        n = n_;
        LOG = 1;

        while ((1LL << LOG) <= max(1LL, n))
            ++LOG;

        g.assign(n, {});
        up.assign(LOG, vll(n));
        depth.assign(n, 0);
    }

    void add_edge(ll u, ll v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(ll u, ll p) {
        up[0][u] = p;

        for (ll j = 1; j < LOG; ++j)
            up[j][u] = up[j - 1][up[j - 1][u]];

        for (ll v : g[u]) {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void build(ll root = 0) {
        dfs(root, root);
    }

    ll kth_ancestor(ll u, ll k) {
        for (ll j = 0; j < LOG; ++j) {
            if (k & (1LL << j))
                u = up[j][u];
        }

        return u;
    }

    ll lca(ll u, ll v) {
        if (depth[u] < depth[v])
            swap(u, v);

        ll diff = depth[u] - depth[v];

        u = kth_ancestor(u, diff);

        if (u == v)
            return u;

        for (ll j = LOG - 1; j >= 0; --j) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    ll distance(ll u, ll v) {
        ll w = lca(u, v);

        return depth[u] + depth[v] - 2 * depth[w];
    }
};

// ================================================================
//                         BINARY SEARCH
// ================================================================

template<typename F>
ll first_true(ll lo, ll hi, F check) {
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}

template<typename F>
ll last_true(ll lo, ll hi, F check) {
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;

        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    return lo;
}

// ================================================================
//                         LIS
// ================================================================

vll lis(const vll& a) {
    vll dp;

    for (ll x : a) {
        auto it = lower_bound(all(dp), x);

        if (it == dp.end())
            dp.pb(x);
        else
            *it = x;
    }

    return dp;
}

// ================================================================
//                       BIT MANIPULATION
// ================================================================

bool is_power_of_two(ll x) {
    return x > 0 && (x & (x - 1)) == 0;
}

ll lowbit(ll x) {
    return x & -x;
}

ll highest_bit(ll x) {
    if (x == 0) return -1;
    return 63 - __builtin_clzll(x);
}

bool getbit(ll x, ll i) {
    return (x >> i) & 1LL;
}

ll setbit(ll x, ll i) {
    return x | (1LL << i);
}

ll clearbit(ll x, ll i) {
    return x & ~(1LL << i);
}

// Enumerate all submasks of mask:
//
// for (ll sub = mask; ; sub = (sub - 1) & mask) {
//     ...
//     if (sub == 0) break;
// }

// ================================================================
//                         SOLVE
// ================================================================

void solve() {

    /*
    Question Simplified

    */

    /*
    Initial Thoughts

    */

    /*
    Algo

    */

    /*
    How to implement

    */
}

// ================================================================
//                           MAIN
// ================================================================

int main() {
    fastio();

    ll t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
