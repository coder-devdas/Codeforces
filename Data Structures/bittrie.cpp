/**
 * Algorithm: Bit Trie (Maximum XOR Pair)
 * Time Complexity: O(log(MAX_VAL)) per insertion/query (typically O(30))
 * Prerequisites: template macros (ll, rep, rev)
 * 
 * Usage:
 * BitTrie trie;
 * trie.insert(5); trie.insert(9);
 * ll max_xor_with_3 = trie.get_max_xor(3); // Finds element in trie that maximizes XOR with 3
 */

struct BitTrie {
    const static ll BITS = 30; // 30 for numbers up to 10^9, 60 for 10^18
    vector<array<ll, 2>> trie;

    BitTrie() {
        trie.push_back({-1, -1}); // Root node
    }

    void insert(ll x) {
        ll node = 0;
        rev(i, BITS - 1, 0) {
            ll bit = (x >> i) & 1;
            if (trie[node][bit] == -1) {
                trie[node][bit] = sz(trie);
                trie.push_back({-1, -1});
            }
            node = trie[node][bit];
        }
    }

    ll get_max_xor(ll x) {
        if (sz(trie) == 1) return 0; // Empty trie
        ll node = 0, ans = 0;
        rev(i, BITS - 1, 0) {
            ll bit = (x >> i) & 1;
            ll target = 1 - bit; // We want the opposite bit to maximize XOR
            
            if (trie[node][target] != -1) {
                ans |= (1LL << i);
                node = trie[node][target];
            } else {
                node = trie[node][bit];
            }
        }
        return ans;
    }
};
