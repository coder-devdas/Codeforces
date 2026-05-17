/**
 * Algorithm: Policy Based Data Structure (Ordered Set)
 * Time Complexity: O(log N) for insertions, deletions, and order statistics
 * Prerequisites: #include <ext/pb_ds/...>
 * Note: To act as a MULTISET, change less<ll> to less_equal<ll> (but erase becomes trickier).
 * 
 * Usage:
 * oset<ll> s;
 * s.insert(5); s.insert(2); s.insert(8);
 * cout << *s.find_by_order(1); // Returns 5 (0-indexed 1st element)
 * cout << s.order_of_key(6); // Returns 2 (Count of elements strictly less than 6)
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
