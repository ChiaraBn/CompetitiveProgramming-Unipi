/*
 * Given an array of N non-negative integers
 * representing the height of blocks at index i as Ai,
 * compute how much water can be trapped in between blocks.
 */

#include <iostream>
#include <vector>
#include <cassert>

int couting (int elem, int& level) {
    if (elem > level) {
        level = elem;
    }

    int count = level - elem;
    return count;
}

void trapping (std:: vector<int> const& array) {
    int start = 0, end = array.size() - 1;
    int level = 0, water = 0;

    while (start != end) {
        if (array[start] <= array[end]) {
            water = water + couting (array[start], level);
            start ++;
        }
        else {        
            water = water + couting (array[end], level);
            end --;
        }
    }

    if (water < 0) {
        water = 0;
    }

    std:: cout << water << std:: endl;
}

int main (void) {

    std:: vector<int> array;
    int t = 0, n = 0, elem = 0;

    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cin >> n;
        array.reserve (n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            array.push_back (elem);
        }
        
        trapping (array);
        array.clear ();
    }

    return 0;
}