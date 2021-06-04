#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    
    int sum = arr[0];
    int max = sum;

    for (int i = 1; i < n; i++) {
        if (sum > 0) {
            sum = sum + arr[i];
        }
        else {
            sum = arr[i];
        }

        if (sum > max) {
            max = sum;
        }        
    }
    return max;
}

int main() {
    int t,n;
    
    cin>>t;
    while(t--) {
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];
            
        cout << maxSubarraySum(a, n) << endl;
    }
}