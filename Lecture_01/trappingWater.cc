#include<bits/stdc++.h>
using namespace std;

int couting (int elem, int& level) {
    if (elem > level) {
        level = elem;
    }

    int count = level - elem;
    return count;
}

int trappingWater(int arr[], int n) {
    int start = 0, end = n - 1;
    int level = 0, water = 0;

    while (start != end) {
        if (arr[start] <= arr[end]) {
            water = water + couting (arr[start], level);
            start ++;
        }
        else {        
            water = water + couting (arr[end], level);
            end --;
        }
    }

    if (water < 0) {
        water = 0;
    }

    return water;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        
        cin >> n;
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }

        cout << trappingWater(a, n) << endl;
    }
    
    return 0;
}