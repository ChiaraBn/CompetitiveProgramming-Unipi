#include <bits/stdc++.h>
#include "../Utils/SegmentTreeMin.cc"
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    int64_t n = 0, m = 0, elem = 0;

    cin >> n;
    vector<int64_t> array;
    array.reserve(n);
 
    for (int i = 0; i < n; i++) {
        cin >> elem;
        array.push_back(elem);
    }

    SegmentTreeMin stm = SegmentTreeMin(array);
    cin >> m;
    cin.ignore();
    
    int64_t l = 0, r = 0, val = 0;
    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        
        ss >> l >> r;
        if (ss >> val) {
            stm.update(l, r, val);
        }
        else {
            cout << stm.rmq(l, r) << endl;
        }
    }

    return 0;
}
