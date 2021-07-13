#include <bits/stdc++.h>
#include "../Utils/FenwickTree.cc"
using namespace std;

int64_t block = 0;

struct query {
    int64_t l, r, x, idx;

    query (int64_t i, int64_t j, int64_t x, int64_t idx) :
        l{i}, r{j}, x{x}, idx{idx}
        {}
};

bool compare (query q1, query q2) {
    if (q1.l/block != q2.l/block)
        return q1.l/block < q2.l/block;

    return q1.r < q2.r;
}

void compute (vector<int64_t> v, vector<query> &q) {
    FenwickTree ft = FenwickTree(v.size());
    vector<int64_t> final;
    final.assign(q.size(), 0);

    block = (int64_t) sqrt(v.size());
    sort(q.begin(), q.end(), compare);

    int64_t cl = 0, cr = -1;
    for (auto qi : q) {
        while (cl < qi.l) {
            ft.add(v[cl], -1);
            cl++;
        }

        while (cl > qi.l) {
            cl--;
            ft.add(v[cl], 1);
        }

        while (cr < qi.r) {
            cr++;
            ft.add(v[cr], 1);
        }

        while (cr > qi.r) {
            ft.add(v[cr], -1);
            cr--;
        }

        final[qi.idx] = ft.sum(qi.x);
    }

    for (auto f:final) {
        cout << f << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);

    int64_t n = 0, m = 0, elem = 0;
    cin >> n >> m;

    vector<int64_t> array;
    array.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> elem;
        array.push_back(elem);
    }

    vector<query> q;
    q.reserve(m);

    int64_t i, j, x;
    for (int a = 0; a < m; a++) {
        cin >> i >> j >> x;
        q.push_back(query(i, j, x, a));
    }

    compute (array, q);

    return 0;
}