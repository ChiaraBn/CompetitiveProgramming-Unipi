
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
    int max = -1;

    for (int i = 0; i < array.size(); i++) {
        if (array[i] >= max) {
            max = array[i];
            std:: cout << max << " ";
        }
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

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            array.push_back(elem);
        }
        
        leaders (array);
        array.clear();
    }

    return 0;
}