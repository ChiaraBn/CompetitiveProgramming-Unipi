#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


void max_value (vector<pair<int, int>> const& a, int capacity) {

    int b[a.size()+1][capacity+1];
    memset(b, 0, sizeof b);

    for (int i = 1; i <= a.size(); i++) {
        int si = a[i-1].first, vi = a[i-1].second;

        for (int j = 1; j <= capacity; j++) {
            if (j - si >= 0){
                b[i][j] = max( b[i-1][j], b[i-1][j-si] + vi );
            }
            else {
                b[i][j] = b[i-1][j];
            }
        }
    }
    cout << b[a.size()][capacity] << endl;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    
    int n = 0, s = 0;
    vector<pair<int, int>> array;

    cin >> s >> n;
    int si = 0, vi = 0;
    for (int i = 0; i < n; i++) {
        cin >> si >> vi;
        array.push_back(make_pair(si, vi));
    }

    max_value (array, s);

    return 0;
}