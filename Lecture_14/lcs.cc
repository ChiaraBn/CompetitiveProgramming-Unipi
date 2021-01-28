#include <bits/stdc++.h>
#include <vector>

const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

int lcs(int x, int y, string s1, string s2){
    int c[x+1][y+1];
    memset(c, 0, sizeof c);
    
    int i = 1, j = 1;
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            if (s1[i-1] == s2[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            }
            else {
                c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
    }
    return c[x][y];
}