#include <iostream>
#include <vector>
#include <algorithm>


void number (std::vector<int64_t> const&a, int64_t sum) {

    int64_t ways = 0, count = 0;
    std:: vector<int64_t> b (a.size(), 0);

    sum = sum /3;
    for (int i = a.size()-1; i >= 0; i--) {
        count += a[i];
        if (count == sum) {
            b[i]++;
        }
    }
    
    int j = a.size()-2;
    while (j >= 0) {
        b[j] += b[j+1];
        j--;
    }

    count = 0;
    for (int i = 0; i < a.size()-2; i++) {
        count += a[i];
        if (count == sum) {
            ways += b[i+2];
        }
    }

    std::cout << ways << std::endl;
    b.clear();
}

int main (void) {
    std::ios_base::sync_with_stdio(false);
    
    int n = 0;
    std::cin >> n;
    std::vector<int64_t> array;
    array.reserve(n); 

    int64_t elem = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> elem;
        sum += elem;
        array.push_back(elem);
    }

    if (sum % 3 != 0) {
        std::cout << "0\n" << std::endl;
    }
    else {
        number (array, sum);
    }

    array.clear();
    return 0;
}