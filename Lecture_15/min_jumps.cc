#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    if (arr[0] == 0) {
        return -1;
    }

    int max_j = arr[0], steps = arr[0], tot = 1;
    for (int i = 1; i < n; i++) {
        if (i == n - 1)
            return tot;

        max_j = max(max_j, i + arr[i]);
        steps--;
        if(steps == 0) {
            tot++;
            if (i >= max_j) {
                return -1;
            }
            steps = max_j - i;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}