/**
 * Algorithm: Sliding Window Maximum (Monotonic Queue)
 * Time Complexity: O(N) total time
 * Prerequisites: template macros (ll, vll, sz, rep, pb)
 * 
 * Usage:
 * vll a = {1, 3, -1, -3, 5, 3, 6, 7};
 * vll max_in_windows = sliding_window_max(a, 3); // Window of size 3
 * // Result: {3, 3, 5, 5, 6, 7}
 */

vll sliding_window_max(const vll& a, ll k) {
    vll res;
    deque<ll> dq; // Stores indices, not values
    
    rep(i, 0, sz(a)) {
        // Remove elements not within the window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // Remove elements that are smaller than the current element
        // (because they will never be the maximum in this or future windows)
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        // Window has reached size k
        if (i >= k - 1) {
            res.pb(a[dq.front()]);
        }
    }
    return res;
}
