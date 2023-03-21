// BINARY SEARCH ITERATIVE ALGORITHM

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& arr, int n) {
    int low=0, high=arr.size()-1, middle;
    while(low<=high) {
        middle=(low+high)/2;
        if(arr[middle]==n) return true;
        if(n<arr[middle]) high=middle-1;
        else low=middle+1;
    }
    return false;
}

int main() {
    vector<int> arr{3,2,5,6,7,1,23,53,74,12,43,59,11};
    sort(arr.begin(), arr.end());
    if(binarySearch(arr, 74)) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;

    return 0;
}