#include <bits/stdc++.h>
#include "../Utils/SegmentTree.cc"

struct segment {
    int64_t l, r, idx;

    segment() {
        l = 0;
        r = 0;
        idx = 0;
    }

    segment (int64_t l, int64_t r, int64_t i) :
        l{l}, r{r}, idx{i} {}
};

bool compare (segment s1, segment s2) {
    return (s1.l < s2.l);
}

void remap (vector<segment> &s, vector<int64_t> singles) {
    for (int i = 0; i < s.size(); i++) {
        s[i].l = lower_bound(singles.begin(), singles.end(), s[i].l) - singles.begin();
        s[i].r = lower_bound(singles.begin(), singles.end(), s[i].r) - singles.begin();
    }
}

void nested (vector<segment> s, vector<int64_t> singles) {
    vector<int64_t> final(s.size());
    
    remap (s, singles);
    sort (s.begin(), s.end(), compare);

    SegmentTree tree = SegmentTree (singles.size());

    for(int i = 0; i < s.size(); i++){
        tree.update(s[i].r, s[i].r, 1);
    }

    for(int i = 0; i < s.size(); i++){
        final[s[i].idx] = tree.sum (s[i].l, s[i].r) -1;
        tree.update(s[i].r, s[i].r, -1);
    }

    for(auto f: final) 
        cout << f << endl; 
}

int main () {
    ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;
    vector<segment> segments;
    segments.reserve(n);
    vector<int64_t> singles;
    
    int64_t l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        segments.push_back(segment(l, r, i));
        singles.push_back(l);
        singles.push_back(r);   
    }
    sort(singles.begin(), singles.end());
    nested (segments, singles);

    return 0;
}