#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


std::vector <int> leaders (int array[], long long n) {
    std:: vector<int> res;
    res.reserve(n);
    int max = array[n-1];

    for (int i = n - 1; i >= 0; i--) {
        if (array[i] >= max) {
            max = array[i];
            res.push_back(max);
        }
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        //calling leaders() function
        vector<int> v = leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}