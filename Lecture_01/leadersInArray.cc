
/* 
 * Given an array of positive integers,
 * return the leaders in the array.
 * An element is a leader if it is greater than or equal to 
 * all the elements to its right side.
 * The rightmost element is always a leader.
 */

#include <iostream>
#include <vector>


void leaders (std:: vector<int> const& array) {
    std:: vector<int> res;
    res.reserve(array.size());
    int max = array.back();


    for (int i = array.size()- 1; i >= 0; i--) {
        if (array[i] >= max) {
            max = array[i];
            res.push_back(max);
        }
    }
    
    for (auto it = res.rbegin(); it != res.rend(); it++) {
        std:: cout << *it <<" ";
    }

    std:: cout << std:: endl;
}


int main (void) {

    std:: vector<int> array;
    int t = 0, n = 0, elem = 0;

    std:: cout << "test cases: ";
    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cout << "size test " << i << ": ";
        std:: cin >> n;
        array.reserve (n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            array.push_back(elem);
        }
        
        leaders (array);
        array.clear();
    }

    return 0;
}