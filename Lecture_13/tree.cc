#include <bits/stdc++.h>
using namespace std;

vector<int> flat, tin, tout, colors;
vector<vector<int>> tree;
int idx = -1;
int64_t block = 0;

struct query {
    int l, r, k, idx;
};

bool compare (query q1, query q2) {
    if (q1.l/block != q2.l/block) {
        return q1.l/block < q2.l/block;
    }
    return q1.r < q2.r;
}

void dfs (int n, int p) {
    tin[n] = ++idx;
    flat[idx] = colors[n];

    for (auto it : tree[n]) {
        if (it != p) {
            dfs (it, n);
        }
    }
    tout[n] = idx;
}

void solve (vector<query> q) {
    block = (int64_t) sqrt (tree.size());
    sort (q.begin(), q.end(), compare);

    vector<int> final;
    final.assign(q.size(), 0);

    vector<int> freq, freq_k;
    freq.assign(1000001, 0);
    freq_k.assign(1000001, 0);

    auto add = [&] (int pos) {
        freq[pos]++;
        freq_k[freq[pos]]++;
    };

    auto remove = [&] (int pos) {
        freq_k[freq[pos]]--;
        freq[pos]--;
    };

    int cl = 0, cr = -1;
    for (int i = 0; i < q.size(); i++) {
        while (cl < q[i].l) {
            //remove
            remove (flat[cl]);
            cl++;
        }

        while (cl > q[i].l) {
            cl--;
            //add
            add (flat[cl]);
        }

        while (cr < q[i].r) {
            cr++;
            //add
            add (flat[cr]);
        }

        while (cr > q[i].r) {
            //remove
            remove (flat[cr]);
            cr--;   
        }
        final[q[i].idx] = freq_k[q[i].k];
    }

    for (auto it : final)
        cout << it << endl;
}

int main () {

    int n, m;
    cin >> n >> m;

    tree.resize(n);
    tin.resize(n);
    tout.resize(n);
    flat.resize(n);
    colors.resize(n);

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        colors[i] = a;
    }

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--; b--;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    dfs (0, -1);

    vector<query> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        q.push_back(query{tin[a], tout[a], b, i});
    }

    solve (q);

    return 0;
}