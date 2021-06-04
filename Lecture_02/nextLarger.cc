#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){

    vector<long long> res;
    deque<long long> d;
    
    for (auto it = arr.rbegin(); it != arr.rend(); it++) {
        while (!d.empty() && *it > d.front()) {
            d.pop_front();
        }   
        if (d.empty()) {
            res.push_back(-1);
        }
        else {
            res.push_back (d.front());
        }
        d.push_front(*it);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}