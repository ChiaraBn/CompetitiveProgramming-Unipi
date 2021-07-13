#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}

int longestSubsequence(int n, int a[])
{
    vector<int> lis(n,0);
    lis[0] = a[0];

    int count = 1;
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.begin()+count, a[i]);  
        
        if (it == lis.begin() + count) {
            lis[count] = a[i];  
            count++;
        }
        else {
            *it = a[i]; 
        } 
    }

    return count;
}
