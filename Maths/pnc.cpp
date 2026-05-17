/**
 * Algorithm: Combinatorics (nCr, nPr)
 * Time Complexity: Precomputation O(N), Query O(1)
 * Prerequisites: binpow(), modInverse(), template macros (rep, rev), const ll MOD
 * 
 * Usage:
 * init_fact();
 * ll ways = nCr(10, 3);
 */

const ll MAX_FACT = 1e6 + 5;
ll fact[MAX_FACT], invFact[MAX_FACT];

void init_fact() {
    fact[0] = 1;
    invFact[0] = 1;
    rep(i, 1, MAX_FACT) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX_FACT - 1] = modInverse(fact[MAX_FACT - 1]);
    rev(i, MAX_FACT - 2, 1) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

ll nPr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[n - r] % MOD;
}
