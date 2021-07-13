#include <bits/stdc++.h>
using namespace std;

void wilbur (vector<int64_t> const &b) {
    vector<int64_t> a (b.size(), 0);
    int64_t count = 0, track = 0;

    for (int i = 0; i < b.size(); i++) {
        int dif = b[i] - (a[i] + track);
        count += abs(dif);
        a[i] = dif + track;
        track = a[i];
    }

    cout << count << endl;
}

int main () {
    ios_base::sync_with_stdio(false);

    int64_t n = 0, elem = 0;
    vector<int64_t> b;
    cin >> n;

    b.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> elem;
        b.push_back(elem);
    }

    wilbur (b);

    return 0;
}