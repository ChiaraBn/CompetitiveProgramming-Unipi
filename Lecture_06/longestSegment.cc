/*
 * Given an array of n integers, a segment is called 'k-good'
 * if it contains no more than k different values.
 * Find any longest k-good segment.
 */

#include <iostream>
#include <vector>
#include <unordered_map>


void longestSegment (std:: vector<int> const &v, int k) {

    std:: unordered_map<int, int> map;

    int i = 0, l = 0;
    int distinct = 0, maxL = 0;
    int left = 0, right = 0;

    while (i < v.size()) {
        
        if (map.find(v[i]) == map.end()) {
            map.insert(std::pair<int, int> {v[i], 0});
            distinct++;
        }
        map[v[i]]++;

        while (distinct > k) {
            map[v[l]]--;
            if (map[v[l]] == 0) 
                distinct--;

            l++;
        }

        if (distinct <= k) {
            if ((i - l)+1 > maxL) {
                maxL = (i - l) + 1;
                right = i;
                left = l;
            }
        }

        i++;
    }

    printf ("%d %d\n", left+1, right+1);   
    map.clear(); 
}


int main (void) {

    std:: vector<int> array;
    int n = 0, k = 0, elem = 0;

    scanf("%d", &n);
    scanf("%d", &k);
    array.reserve(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        array.push_back(elem);
    }

    longestSegment (array, k);

    array.clear();
    return 0;
}