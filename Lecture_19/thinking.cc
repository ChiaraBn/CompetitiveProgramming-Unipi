#include <bits/stdc++.h>
using namespace std;

int64_t flip (string const& seq) {
    int64_t count = 1, check = 0;

    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] != seq[check]) {
            count++;
            check = i;
        }
    }

    if (count == seq.size()) {
        return count;
    }
    else if (count <= seq.size()-2) {
        return count += 2;
    }
    else if (count == seq.size() -1) {
        return count += 1;
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);

    int64_t n = 0;
    cin >> n;
    
    string seq;
    seq.reserve(n);
    cin >> seq;

    cout << flip (seq) << endl;

    return 0;
}