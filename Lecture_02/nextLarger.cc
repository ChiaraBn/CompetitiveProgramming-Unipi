/* 
 * Given an array of size N having distinct elements,
 * find for each the next greater element in the array,
 * in order of their appearance.
 * If no such element exists, return -1.
 */

#include <iostream>
#include <vector>
#include <deque>


void nextLargerElem (std:: vector<long int> const &a) {
    std:: vector<long int> res;
    res.reserve(a.size());

    std:: deque<long int> d;
    
    for (auto it = a.rbegin(); it != a.rend(); it++) {
        while (d.size() > 0 && *it > d.front()) {
            d.pop_front();
        }           
  
        if (d.size() == 0) {
            res.push_back(-1);
        }
        else {
            res.push_back(d.front());
        } 

        d.push_front(*it);
    }

    for (auto it = res.rbegin(); it != res.rend(); it++) {
        printf("%ld ", *it);
    }
    printf("\n");

    res.clear();
    d.clear();
}


int main (void) {

    std:: vector<long int> array;
    int t = 0, n = 0;
    long int elem = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        array.reserve (n);

        for (int j = 0; j < n; j++) {
            scanf("%ld", &elem);
            array.push_back(elem);
        }

        nextLargerElem(array);  
        array.clear();
    }

    return 0;
}