#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}

int MissingNumber(vector<int>& array, int n) {
    int tot_sum = 0, sum = 0;

    for (int j = 0; j < n-1; j++) {
        sum += array[j];
        array.push_back(array[j]);
    }

    tot_sum = n * (n+1) / 2;
    return (tot_sum - sum);
}