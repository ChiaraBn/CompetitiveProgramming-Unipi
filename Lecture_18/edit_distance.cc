#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t) {
    int ed[s.length()+1][t.length()+1];

    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j <= t.length(); j++) {
            if (i == 0)
                ed[i][j] = j;
            else if (j == 0) 
                ed[i][j] = i;

            else if (s[i-1] == t[j-1])
                ed[i][j] = ed[i-1][j-1];
            else
                ed[i][j] = min(
                    min(ed[i-1][j-1], ed[i-1][j]),
                    ed[i][j-1]
                ) +1;
        }
    }

    return ed[s.length()][t.length()];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        int ans = editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}