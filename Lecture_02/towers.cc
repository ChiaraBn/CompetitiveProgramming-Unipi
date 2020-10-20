/*
 * Given a kit consists of several wooden bars, 
 * the lengths of all of them are known.
 * The bars can be put one on the top of the other 
 * if their lengths are the same.
 * Construct the minimal number of towers, from the bars.
 * 
 * Output: the height of the largest tower and their total number.
 */

#include <iostream>
#include <vector>
#include <algorithm>


void find_towers (std:: vector<int> const &v) {

    int height = 0, lenght = 0, towers = 0, max = 1;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == lenght) {
            height++;

            if (height > max)
                max = height;
        }
        else {
            lenght = v[i];
            towers++;
            height = 1;
        }
    }

    std:: cout << max << " " << towers << std:: endl;
}


int main (void) {

    std:: vector<int> array;
    int n = 0, elem = 0;

    std:: cin >> n;
    array.reserve(n);

    for (int i = 0; i < n; i++) {
        std:: cin >> elem;
        array.push_back(elem);
    }

    std:: sort(array.begin(), array.end());
    find_towers(array);
    array.clear();

    return 0;
}