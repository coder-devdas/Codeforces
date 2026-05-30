// Author: Coder Devdas
#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

// ----------------------------- Aliases -----------------------------
using ll  = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

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
#define rep(i,a,b)   for (ll i = (a); i < (b); ++i)
#define rev(i,a,b)   for (ll i = (a); i >= (b); --i)
#define each(x, a)  for (auto& x : a)

// ----------------------------- Constants -----------------------------
const ll MOD = 1e9 + 7;
const ll INF = 2e18;
const ld EPS = 1e-9;

// ============================ INPUT SHORTCUTS ============================
// 1. Read Pairs directly
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { return in >> p.ff >> p.ss; }
// 2. Read Vectors directly
template<typename T> istream& operator>>(istream& in, vector<T>& v) { for(auto &x : v) in >> x; return in; }
// 3. Read Multiple Variables of any type at once: read(a, b, c, string_name, vector_name);
template<typename... T> void read(T&... args) { ((cin >> args), ...); }
// 4. Resize and read a vector in one line
template<typename T> void ivec(ll n, vector<T>& v) { v.resize(n); for(auto &x : v) cin >> x; }

// ============================ OUTPUT SHORTCUTS ============================
// 1. Print Pairs directly (space separated)
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& p) { return out << p.ff << " " << p.ss; }
// 2. Print Vectors directly (space separated)
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { 
    for(int i=0; i<sz(v); ++i) out << v[i] << (i == sz(v)-1 ? "" : " "); return out; 
}
// 3. Print Multiple Variables separated by space: print(a, b, "hello", v);
template<typename T, typename... Args> void print(T&& first, Args&&... args) {
    cout << first; ((cout << " " << forward<Args>(args)), ...);
}
// 4. Same as print, but adds a newline at the end automatically
template<typename... Args> void println(Args&&... args) {
    if constexpr (sizeof...(args) > 0) print(forward<Args>(args)...); cout << '\n';
}
// 5. Quick YES/NO printers (Very common in CP)
void YES(bool t = true) { cout << (t ? "YES\n" : "NO\n"); }
void Yes(bool t = true) { cout << (t ? "Yes\n" : "No\n"); }


// ----------------------------- Debugging -----------------------------
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]"; }

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

// ----------------------------- Fast I/O -----------------------------
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// ----------------------------- Solve -----------------------------
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

// ----------------------------- Main -----------------------------
int main() {
    fastio();
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
