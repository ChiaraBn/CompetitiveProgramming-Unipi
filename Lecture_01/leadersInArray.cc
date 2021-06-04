#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n){
    vector<int> l;

    int max = a[n-1];
    for (int i = n-1; i >= 0; i--) {
        if (a[i] >= max) {
            l.push_back(a[i]);
            max = a[i];
        }
    }
    reverse(l.begin(), l.end());
    return l;
}

int main() {

   long long t;
   cin >> t;
   while (t--) {
        long long n;
        cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        vector<int> v = leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;
   }
}