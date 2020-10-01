/*
 * Given an array on N integers, find the
 * contigous sub-array with the maximum sum.
 * Print the maximum sum.
 */

#include <iostream>
#include <vector>


void maximum_sum (std:: vector<int> const& array) {
    int sum = array.front();
    int max = sum;

    for (int i = 1; i < array.size(); i++) {
        if (sum > 0) {
            sum = sum + array[i];
        }
        else {
            sum = array[i];
        }

        if (sum > max) {
            max = sum;
        }        
    }
    std:: cout << max << std:: endl;
}

int main (void) {

    std:: vector<int> array;
    int t = 0, n = 0, elem = 0;

    std:: cout << "test cases: ";
    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cout << "size test " << i <<": ";
        std:: cin >> n;
        array.reserve (n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            array.push_back (elem);
        }
        
        maximum_sum (array);
        array.clear ();
    }

    return 0;
}