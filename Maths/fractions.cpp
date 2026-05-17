/**
 * Utility: Exact Fraction / Rational Math
 * Why use it?: Floating point (double) math causes precision errors. This struct compares slopes/ratios exactly.
 * Time Complexity: O(log(min(a,b))) for GCD simplification
 * Prerequisites: template macros (ll)
 * 
 * Usage:
 * Fraction f1(2, 4); // Automatically simplifies to 1/2
 * Fraction f2(1, 3);
 * if (f1 > f2) cout << "No precision bugs here!";
 */

struct Fraction {
    ll n, d; // numerator, denominator

    Fraction(ll _n = 0, ll _d = 1) {
        ll g = std::gcd(abs(_n), abs(_d));
        n = _n / g;
        d = _d / g;
        if (d < 0) { n = -n; d = -d; } // keep denominator positive
    }

    bool operator==(const Fraction& o) const { return n == o.n && d == o.d; }
    bool operator!=(const Fraction& o) const { return !(*this == o); }
    
    // Cross-multiplication prevents precision loss. 
    // Uses __int128_t to prevent overflow during multiplication.
    bool operator<(const Fraction& o) const { 
        return (__int128_t)n * o.d < (__int128_t)o.n * d; 
    }
    bool operator>(const Fraction& o) const { return o < *this; }
    bool operator<=(const Fraction& o) const { return !(o < *this); }
    bool operator>=(const Fraction& o) const { return !(*this < o); }

    // Math operations
    Fraction operator+(const Fraction& o) const { return Fraction(n * o.d + o.n * d, d * o.d); }
    Fraction operator-(const Fraction& o) const { return Fraction(n * o.d - o.n * d, d * o.d); }
    Fraction operator*(const Fraction& o) const { return Fraction(n * o.n, d * o.d); }
    Fraction operator/(const Fraction& o) const { return Fraction(n * o.d, d * o.n); }
};
