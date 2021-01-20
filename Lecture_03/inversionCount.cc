/*
 * Given an array of N distinct positive integers,
 * count the number of inversions.
 * Note that an inversion occurs if i < j and A[i] > A[j].
 */

#include <iostream>
#include <vector>


long int merge (std:: vector<int> &left, std:: vector<int> &right,
                std:: vector<int> &v) {
    
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    long int inversions = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            v[i] = left[j];
            j++;
        }
        else {
            v[i] = right[k];
            k++;

            inversions += nL - j;
        }
        i++;
    }

    while (j < nL) {
        v[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        v[i] = right[k];
        k++; i++;
    }

    return inversions;
} 

long int mergeSort (std:: vector<int> &v) {
    if (v.size() <= 1) 
        return 0;

    int middle = v.size() / 2;
    std:: vector<int> left;
    std:: vector<int> right;

    for (unsigned long j = 0; j < middle; j++)
        left.push_back(v[j]);

    for (unsigned long j = 0; j < (v.size()) - middle; j++)
        right.push_back(v[middle + j]);

    long int lCount = mergeSort(left);
    long int rCount = mergeSort(right);

    return lCount + rCount + merge(left, right, v);
}

int main (void) {
    std:: vector<int> array;
    int t = 0, n = 0, elem = 0;

    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cin >> n;
        array.reserve(n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            array.push_back(elem);
        }
        
        long int res = mergeSort(array);
        std:: cout << res << std:: endl;
        array.clear();
    }

    return 0;
}