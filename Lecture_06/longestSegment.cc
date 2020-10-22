/*
 * Given an array of n integers, a segment is called 'k-good'
 * if it contains no more than k different values.
 * Find any longest k-good segment.
 */

#include <iostream>
#include <vector>
#include <unordered_map>


std::pair<int, int> longestSegment (std:: vector<int> const &v, int k) {

    std:: unordered_map<int, int> map;

    int r = 0, l = 0;
    int maxL = 0, diff = 0;
    std::pair<int, int> p;

    while (r < v.size()) {      
        if (map.find(v[r]) == map.end()) {
            map.insert(std::pair<int, int> {v[r], 1});
        }
        else {
            map.find(v[r]) -> second ++;
        }

        while (map.size() > k) {
            map[v[l]]--;

            if (map[v[l]] == 0) {
                map.erase(v[l]);
            }
            ++l;
        }

        diff = r - l;
        if (diff >= maxL) {
            maxL = diff;
            p = std::make_pair(l, r);
        }
        ++r;
    }

    return p;
}


int main (void) {

    std:: vector<int> array;
    int n = 0, k = 0;
    int elem = 0;

    scanf("%d", &n);
    scanf("%d", &k);
    array.reserve(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        array.push_back(elem);
    }

    std::pair<int, int> pair = longestSegment (array, k);
    printf("%d ", pair.first+1);
    printf("%d ", pair.second+1);
    printf("\n");

    array.clear();
    return 0;
}