#include <bits/stdc++.h>
#include "../Utils/FenwickTree.cc"
using namespace std;

struct update {
    int l, r, val;

    update(int l, int r, int val) : l{l}, r{r}, val{val} {}
};

void update_array (int n, vector<update> const& ups, vector<int> const &qs) {
    FenwickTree ft = FenwickTree(n);

    for (int i = 0; i < ups.size(); i++) {
        ft.add(ups[i].l, ups[i].val);
        ft.add(ups[i].r + 1, (ups[i].val*(-1)));
    }

    for (int i = 0; i < qs.size(); i++) {
        int sum = ft.sum(qs[i]);
        cout << sum << endl;
    }
}

int main() {

    int t = 0, n = 0, u = 0, q = 0;
    int l = 0, r = 0, val = 0;

    cin >> t;
    vector<update> ups;
    vector<int> qs;

    while (t > 0) {
        cin >> n >> u;
        ups.reserve(u);

        for (int i = 0; i < u; i++) {
            cin >> l >> r >> val;
            ups.push_back(update(l,r,val));
        }

        cin >> q;
        qs.reserve(q);
        for (int i = 0; i < q; i++) {
            cin >> val;
            qs.push_back(val);
        }

        update_array (n, ups, qs);

        ups.clear();
        qs.clear();
        t--;
    }

    return 0;
}