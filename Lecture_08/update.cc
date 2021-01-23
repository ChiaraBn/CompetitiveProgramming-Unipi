#include <iostream>
#include <vector>

struct update {
    int l;
    int r;
    int val;

    update (int left, int right, int val) : 
        l{left}, 
        r{right}, 
        val{val} 
        {}
};

void update_array (int n, std::vector<update> const&u, std::vector<int> const&q) {
    std::vector<int> a (n, 0);
    std::vector<int> b (n, 0);

    // dynamic prefix sum
    for (int i = 0; i < u.size(); i++) {
        b[u[i].l] += u[i].val;
        b[u[i].r+1] -= u[i].val;
    }

    a[0] = b[0];
    for (int i = 1; i < n; i++) {
        a[i] = a[i-1] + b[i];
    }

    for (int i = 0; i < q.size(); i++) {
        std::cout << a[q[i]] << std::endl;
    }

    a.clear();
    b.clear();
}

int main (void) {
    std::ios_base::sync_with_stdio(false);

    std::vector<int> queries;
    std::vector<update> updates;

    int t = 0, n = 0, u = 0, q = 0;
    int l = 0, r = 0, val = 0;

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n >> u;
        updates.reserve(u);

        for (int j = 0; j < u; j++) {
            std::cin >> l >> r >> val;
            update up = update (l, r, val);
            updates.push_back(up);
        }

        std::cin >> q;
        queries.reserve(q);
        int elem = 0;
        for (int j = 0; j < q; j++){
            std::cin >> elem;
            queries.push_back(elem);
        }

        update_array (n, updates, queries);

        queries.clear();
        updates.clear();
    }
    
    return 0;
}