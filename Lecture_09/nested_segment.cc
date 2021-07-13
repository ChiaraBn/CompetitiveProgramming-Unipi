#include <bits/stdc++.h>
#include "../Utils/FenwickTree.cc"
using namespace std;

struct segment {
    int start, end, idx;

    segment (int s, int e, int i) :
        start{s}, end{e}, idx{i} {}
};

bool compare (segment p1, segment p2) {
    return p1.start < p2.start;
}

void compute (vector<segment> v, vector<int> elem) {
    FenwickTree ft = FenwickTree(elem.size());
    vector<int> final;
    final.assign(v.size(), 0);

    //remap
    for (int i = 0; i < v.size(); i++) {
        v[i].start = lower_bound(elem.begin(), elem.end(), v[i].start) - elem.begin();
        v[i].end = lower_bound(elem.begin(), elem.end(), v[i].end) - elem.begin();
    }
    
    sort (v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        ft.add(v[i].end, 1);
    }

    for (int i = 0; i < v.size(); i++) {
        final[v[i].idx]= ft.sum(v[i].end)-1;
        ft.add(v[i].end, -1);
    }

    for (auto it: final)
        cout << it << endl;
}

int main () {
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<segment> array;
    array.reserve(n);
    vector<int> elem;
    
    int s, e;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        array.push_back(segment(s, e, i));
        elem.push_back(s);
        elem.push_back(e);
    }

    sort (elem.begin(), elem.end());
    compute (array, elem);

    return 0;
}