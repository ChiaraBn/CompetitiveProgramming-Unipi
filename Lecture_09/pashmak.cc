#include <bits/stdc++.h>
#include "../Utils/FenwickTree.cc"
using namespace std;

void pairs(vector<int64_t> const& v) {
    FenwickTree ft = FenwickTree(v.size());
    vector<int64_t>freq(v.size(), 0);
    map<int64_t, int64_t> counter;
    int64_t ans = 0;

    for (int i = v.size()-1; i >= 0; i--) {
        counter[v[i]]++;
        freq[i] = counter[v[i]];
        ft.add(freq[i], 1);
    }

    counter.clear();
    for (int i = 0; i < v.size(); i++) {
        counter[v[i]]++;
        ft.add(freq[i], -1);
        ans += ft.sum(counter[v[i]]-1);
    }

    cout << ans << endl;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    int n = 0;
    int64_t elem = 0;

    cin >> n;
    vector<int64_t> elems;
    elems.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> elem;
        elems.push_back(elem);
    }

    pairs(elems);

    return 0;
}