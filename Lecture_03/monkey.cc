/*
 * Original problem at: 
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3183
 */

#include <iostream>
#include <vector>


void findK (std:: vector<long int> const &v, int num) {
    int k = 0, diff = 0;

    for (int i = v.size()-1; i >= 0; i--) {
        if (i == 0) {
            diff = v[i];
        }
        else {
            diff = v[i] - v[i-1];
        }

        if (diff > k) {
            k = diff;
        }
        else if (diff == k) {
            k = diff + 1;
        }
    }
    
    std:: cout << "Case " << num << ": " << k << std:: endl;
}


int main (void) {
    
    std:: vector<long int> ladder;
    int t = 0, n = 0;
    long int elem = 0;

    std:: cin >> t;

    for (int i = 0; i < t; i++) {
        std:: cin >> n;
        ladder.reserve (n);

        for (int j = 0; j < n; j++) {
            std:: cin >> elem;
            ladder.push_back(elem);
        }

        findK (ladder, i+1);
        ladder.clear();
    }

    return 0;
}