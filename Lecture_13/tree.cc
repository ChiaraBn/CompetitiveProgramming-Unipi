#include <bits/stdc++.h>
using namespace std;

struct query {
    int64_t l, r, k, idx;
};

vector<int64_t> colors;                 
vector<vector<int64_t>> tree;    
vector<query> qs;  
vector<int64_t> freq, freq_k, final;          
vector<int64_t> l, r, flat_tree;               
int64_t remap_idx = 0, block = 512, n, m;                

void dfs(int64_t u, int64_t p) {
    l[u] = ++remap_idx;
    flat_tree[remap_idx] = colors[u];

    for(int v : tree[u]) {
        if(v != p) dfs(v, u);
    }
    r[u] = remap_idx;
}

bool compare (query q1, query q2) {
    if (q1.l/block != q1.l/block)
        return q1.l/block < q2.l/block;

    return q1.r < q2.r;
}

void compute () {
    sort (qs.begin(), qs.end(), compare);

    auto add = [&](int pos) {
        freq[flat_tree[pos]]++;
        freq_k[freq[flat_tree[pos]]]++;
    };

    auto remove = [&](int pos) {
        freq_k[freq[flat_tree[pos]]]--;
        freq[flat_tree[pos]]--;
    };

    int cl = qs[0].l;
    int cr = cl-1;
    for(int i = 0; i < m; i++) {
        while(cl > qs[i].l) {
            add(--cl);
        }

        while(cl < qs[i].l) {
            remove(cl++);
        }
            
        while(cr < qs[i].r) {
            add(++cr);
        }  
            
        while(cr > qs[i].r) {
            remove(cl--);
        }
            
        final[qs[i].idx] = freq_k[qs[i].k];
    }

    for (int i = 0; i < m; i++) {
        cout << final[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    colors.resize(n+1);
    tree.resize(n+1);
    qs.reserve(m);
    l.resize(n+1, 0);
    r.resize(n+1, 0);
    flat_tree.resize(n+1, 0);
    final.resize(m+1, 0);  

    freq.resize(1e5+1, 0);
    freq_k.resize(1e5+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    for(int i = 1; i < n; i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1);

    for(int i = 0 ; i < m; i++) {
        int vi, k;
        cin >> vi >> k;
        vi--;
        qs.push_back(query{l[vi],r[vi], k, i});
    }

    compute();

    return 0;
}