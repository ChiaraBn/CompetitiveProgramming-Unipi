#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

    vector<int> compute (vector<int> const &v, bool flag) {
        vector<int> res (v.size(), 1);

        if (flag) {
            for (int i = 1; i < v.size(); i++) {
                for (int j = 0; j < i; j++)
                    if (v[j] < v[i] && res[i] < res[j]+1)
                        res[i] = res[j]+1;
            }
        }
        else {
            for (int i = v.size()-2; i >= 0; i--) {
                for (int j = v.size()-1; j > i; j--)
                    if (v[j] < v[i] && res[i] < res[j]+1)
                        res[i] = res[j]+1;
            }
        }
        return res;
    }

	int LongestBitonicSequence(vector<int>nums)
	{
        vector<int> lis = compute (nums, true);
        vector<int> lds = compute (nums, false);
	    
        for (int i = 0; i < lis.size(); i++) {
            lis[i] = (lis[i] + lds[i]) -1;
        }
        return *max_element (lis.begin(), lis.end());
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}