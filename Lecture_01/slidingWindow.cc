#include <bits/stdc++.h>
using namespace std;


vector <int> max_of_subarrays(int *arr, int n, int k) {
    std:: deque<int> deque;
    std:: vector<int> res;

    for (int i = 0; i < n; i++) {
        if (! deque.empty()) {
            if (deque.front() <= i - k) {
                deque.pop_front();
            }

            while (deque.size() > 0 and arr[i] >= arr[deque.back()]) {
                deque.pop_back();
            }
        }

        deque.push_back(i);

        if (i >= k - 1) {
            res.push_back(arr[deque.front()]);
        }
    }
    return res;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  