#include <bits/stdc++.h>
#include "../Utils/FenwickTree.cc"
using namespace std;

void triplets (vector<int64_t> const &v) {
    FenwickTree lt = FenwickTree(v.size());
    FenwickTree gt = FenwickTree(v.size());
    int64_t result = 0;

    for (int i = 0; i < v.size(); i++) {
        gt.add(v[i], 1);
    }

    for(int i = 0; i < v.size();i++){
        result += lt.sum(v[i]-1)*(gt.sum(v.size()-1)-gt.sum(v[i]));
        lt.add(v[i],1);
        gt.add(v[i],-1);
    }
    cout << result << endl;
}

int main () {
    ios_base::sync_with_stdio(false);

    int64_t n = 0, elem = 0;
    cin >> n;

    vector<int64_t> array;
    array.reserve(n);

    for (int i = 0; i< n; i++) {
        cin >> elem;
        array.push_back(elem);
    }

    triplets(array);

    return 0;
}