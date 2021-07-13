#include <bits/stdc++.h>
using namespace std;

int64_t block = 0;

struct range {
    int64_t l, r, idx;

    range(int64_t l, int64_t r, int64_t idx) : 
        l{l}, r{r}, idx{idx} {}
};

bool compare (range r1, range r2) {
    if (r1.l/block != r2.l/block)
        return r1.l/block < r2.l/block;
 
    // Same block, sort by ending value
    return r1.r < r2.r;
}

vector<int64_t> power (vector<int64_t> const &v, vector<range> &qs,
                      vector<int64_t> &powers) {

    int64_t cl = 0, cr = -1, count = 0;
    vector<int64_t> freq;
    freq.assign(10000001, 0); 

    for (int i = 0; i < qs.size(); i++) {
        while (cl < qs[i].l) {
            count -= (2*(freq[v[cl]])-1) * v[cl];
            freq[v[cl]]--;
            cl++;
        }

        while (cl > qs[i].l) {
            cl--;
            count += (2*(freq[v[cl]])+1) * v[cl];
            freq[v[cl]]++;
        }

        while (cr < qs[i].r) {
            cr++;
            count += (2*(freq[v[cr]])+1) * v[cr];
            freq[v[cr]]++;
        }

        while (cr > qs[i].r) {
            count -= (2*(freq[v[cr]])-1) * v[cr];
            freq[v[cr]]--;
            cr--;
        }

        powers[qs[i].idx] = count;
    }
    return powers;
}

void compute (vector<int64_t> const &v, vector<range> &qs)  {
    vector<int64_t> powers;
    powers.assign(qs.size(), 0);

    block = int64_t(sqrt(v.size()));
    sort (qs.begin(), qs.end(), compare);

    powers = power (v, qs, powers);

    for (auto p: powers) {
        cout << p << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);

    int64_t n = 0, t = 0, elem = 0;
    int64_t l = 0, r = 0;
    cin >> n >> t;

    vector<int64_t> array;
    array.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> elem;
        array.push_back(elem);
    }

    vector<range> q;
    q.reserve(t);
    for (int i = 0; i < t; i++) {
        cin >> l >> r;
        q.push_back(range(l-1, r-1, i));
    }

    compute (array, q);
    return 0;
}