/*
 * Original problem at:
 * https://codeforces.com/problemset/problem/313/B?locale=en
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;


void find_solution (string const &seq, vector<pair<int, int>> const &q) {
    vector<int> b (seq.length()+1);
    b[0] = 0;
    for (int i = 1; i < seq.length(); i++) {
        b[i] = (seq[i] == seq[i-1])? b[i-1] + 1 : b[i-1];
    }
    b[seq.length()] = b[(seq.length()) - 1];

    for (int j = 0; j < q.size(); j++) {
        cout << b[q[j].second-1] - b[q[j].first-1] << endl;        
    }

    b.clear();
}


int main (void) {
    std::ios_base::sync_with_stdio(false);

    int m = 0;
    string seq;
    vector<pair<int, int>> queries;

    cin >> seq;
    cin >> m;
    queries.reserve(m);

    int l = 0, r = 0;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        queries.push_back(make_pair(l,r));
    }

    find_solution(seq, queries);
    queries.clear();
    seq.clear();

    return 0;
}