#include<bits/stdc++.h>
using namespace std;


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
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
    
int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}