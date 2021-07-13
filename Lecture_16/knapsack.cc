#include <bits/stdc++.h>
using namespace std;

void knapsack (vector<pair<int, int>> const &v, int cap) {
    int b[cap+1][v.size()+1];
    memset (b, 0, sizeof b);
        
    for (int i = 1; i <= cap; i++) {
        for (int j = 1; j <= v.size(); j++) {
            int sj = v[j-1].first, vj = v[j-1].second;

            if (i - sj >= 0) {
                b[i][j] = max(b[i][j-1], b[i-sj][j-1] + vj);
            }
            else {
                b[i][j] = b[i][j-1];
            }
        }
    }

    cout << b[cap][v.size()] << endl;
}

int main () {
    ios_base::sync_with_stdio(false);

    int s = 0, n = 0;
    cin >> s >> n;

    int size = 0, value = 0;
    vector<pair<int, int>> items;
    items.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> size >> value;
        items.push_back(make_pair(size, value));
    }

    knapsack (items, s);

    return 0;
}