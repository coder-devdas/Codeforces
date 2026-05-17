/**
 * Algorithm: Sieve of Eratosthenes, SPF, and Divisors
 * Time Complexity: Sieve O(N log log N), Factorize O(log N), Divisors O(sqrt(N))
 * Prerequisites: template macros (ll, vll, pb, rep, all)
 * 
 * Usage:
 * init_sieve();
 * vpll factors = get_factorization(12); // returns {{2,2}, {3,1}}
 * vll divs = get_divisors(36); // returns sorted divisors: {1, 2, 3, 4, 6, 9, 12, 18, 36}
 */

const ll MAXN = 1e6 + 5;
ll spf[MAXN];

void init_sieve() {
    iota(spf, spf + MAXN, 0);
    rep(i, 2, MAXN) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vpll get_factorization(ll x) {
    vpll ret;
    while (x != 1) {
        ll p = spf[x], cnt = 0;
        while (x % p == 0) { cnt++; x /= p; }
        ret.pb({p, cnt});
    }
    return ret;
}

vll get_divisors(ll n) {
    vll divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            if (i * i != n) divs.pb(n / i);
        }
    }
    sort(all(divs));
    return divs;
}
