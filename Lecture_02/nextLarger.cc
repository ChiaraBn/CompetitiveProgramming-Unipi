/* 
 * Given an array of size N having distinct elements,
 * find for each the next greater element in the array,
 * in order of their appearance.
 * If no such element exists, return -1.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>


void nextLargerElem (std:: vector<int> const &a) {
    std:: vector<int> res;
    res.reserve(a.size());

    std:: deque<int> d;
    
    for (int i = a.size()-1; i >= 0; i--) {
        if (! d.empty()) {
            auto it = d.begin();

            while (it != d.end() and a[i] > *it) {
                it ++;
            }

            d.push_front(a[i]);
            if (it == d.end()) {
                res.push_back(-1);
            }
            else {
                res.push_back(*it);
            }
        }
        else {
            d.push_front(a[i]);
            res.push_back(-1);       
        }
    }

    std:: reverse (res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        std:: cout << res[i] << " ";
    }
    std:: cout << std:: endl;

    res.clear();
    d.clear();
}


int main (void) {

    std:: vector<int> array;
    int t = 0, n = 0, elem = 0;

    std:: cout << "test cases: ";
    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cin >> n;
        array.reserve (n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            array.push_back(elem);
        }

        nextLargerElem(array);
        array.clear();
    }

    return 0;
}