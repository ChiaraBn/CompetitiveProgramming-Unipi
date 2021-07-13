#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
    
        if (sum % 2 != 0)
            return 0;
    
        int half = sum/2;
        bool b[half+1][N+1];
        
        for (int i = 0; i <= N; i++)
            b[0][i] = 1;
        for (int i = 1; i <= half; i++)
            b[i][0] = 0;

        for (int i = 1; i <= half; i++) {
            for (int j = 1; j <= N; j++) {
                b[i][j] = b[i][j - 1];

                if (i >= arr[j - 1])
                    b[i][j] = b[i][j] || b[i-arr[j-1]] [j-1];
            }
        }
    
        return b[half][N];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}