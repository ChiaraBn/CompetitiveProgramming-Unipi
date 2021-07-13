#include <bits/stdc++.h>
using namespace std;

struct node {
    pair<int, int> part;
    vector<int> edges;

    node() {
        part.first = -1;
        part.second = -1;
    }
};

int compute (vector<node> &t, int i, int p, bool flag) {
    int sum = (flag)? 1 : 0;
    
    if (flag) {
        if (t[i].part.first == -1) {
            for (int j : t[i].edges) {
                if (j != p) {
                    sum += min(
                        compute(t, j, i, true),
                        compute(t, j, i, false)
                    );
                }
            }
            t[i].part.first = sum;
        }
        else 
            sum = t[i].part.first;
    }
    else {
        if (t[i].part.second == -1) {
            for (int j : t[i].edges) {
                if (j != p) 
                sum += compute(t, j, i, true);
            }
            t[i].part.second = sum;
        }
        else
            sum = t[i].part.second;
    }

    return sum;
}

int main(void) {

    int n = 0;
    cin >> n;
    vector<node> tree(n);

    int u = 0, v = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        tree[u-1].edges.push_back(v-1);
        tree[v-1].edges.push_back(u-1);
    }

    cout << min(compute(tree, 0, -1, false), compute(tree, 0, -1, true)) << endl;

    return 0;
}