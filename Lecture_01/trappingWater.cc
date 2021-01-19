#include<bits/stdc++.h>

using namespace std;


// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int couting (int elem, int& level) {
    if (elem > level) {
        level = elem;
    }

    int count = level - elem;
    return count;
}

int trappingWater(int arr[], int n){
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
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}