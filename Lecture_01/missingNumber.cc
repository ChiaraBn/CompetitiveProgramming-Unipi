
/*
 * Given an array C of size N-1 and given
 * that there are numbers from 1 to N, with one element
 * missing, find the missing element.
 */

#include <iostream>
#include <vector>


int main (void) {
    std:: vector<int> array;
    int t = 0, n = 0, elem = 0;
    int sum = 0, tot_sum = 0;

    std:: cout << "test cases: ";
    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cout << "size test " << i << ": ";
        std:: cin >> n;
        array.reserve (n);

        for (int j = 0; j < n-1; j++) {
            std:: cin >> elem;
            sum += elem;
            array.push_back(elem);
        }

        tot_sum = n * (n+1) / 2;
        std:: cout << tot_sum - sum << std:: endl;

        sum = 0;
        array.clear ();
    }

    return 0;
}