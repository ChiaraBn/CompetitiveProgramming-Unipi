/*
 * Given an array A and a integer k, find the
 * maximum for each and every cotnigous subarrays
 * of size k
 */

#include <iostream>
#include <vector>
#include <deque>


void window (std:: vector<int> const &v, int k) {
    std:: deque<int> deque;
    std:: vector<int> res;

    for (int i = 0; i < v.size(); i++) {
        if (! deque.empty()) {
            if (deque.front() <= i - k) {
                deque.pop_front();
            }

            while (deque.size() > 0 and v[i] >= v[deque.back()]) {
                deque.pop_back();
            }
        }

        deque.push_back(i);

        if (i >= k - 1) {
            res.push_back(v[deque.front()]);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        std:: cout << res[i] << " ";
    }
    std:: cout << std:: endl;

    res.clear();
    deque.clear();
}

int main (void) {
    std:: vector<int> vector;
    int t = 0, n = 0, elem = 0, k = 0;

    std:: cout << "test cases: ";
    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cin >> n;
        std:: cin >> k;
        vector.reserve (n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            vector.push_back (elem);
        }

        window (vector, k);
        vector.clear();
    }

    return 0;
}