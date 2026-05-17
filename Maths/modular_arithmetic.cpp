/**
 * Algorithm: Modular Arithmetic & Extended GCD
 * Time Complexity: O(log(MOD)) for pow/inverse, O(log(min(a,b))) for extgcd
 * Prerequisites: const ll MOD
 * 
 * Usage:
 * ll ans = binpow(2, 10);
 * ll inv = modInverse(5);
 * ll x, y; ll gcd_val = extgcd(A, B, x, y); // Solves Ax + By = GCD(A, B)
 */

ll binpow(ll a, ll b, ll m = MOD) {
    a %= m; ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m; b >>= 1;
    }
    return res;
}

ll modInverse(ll n, ll m = MOD) {
    return binpow(n, m - 2, m);
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b);
    return d;
}
