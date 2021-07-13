#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq (string A);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << longestPalinSubseq (s) << endl;
    }
}

int longestPalinSubseq (string S)
{
    string s1 = S;
    reverse(S.begin(), S.end());

    //lcs
    int c[S.length()+1][S.length()+1];
    memset(c, 0, sizeof c);

    for (int i = 1; i <= S.length(); i++) {
        for (int j = 1; j <= S.length(); j++) {
            if (s1[i-1] == S[j-1])
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = max(c[i][j-1], c[i-1][j]);
        }
    }
    return c[S.length()][S.length()];
}