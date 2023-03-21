// BINARY SEARCH RECURSIVE ALGORITHM

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& arr, int n, int low, int high) {
    if(low>high) return false;

    int middle=(low+high)/2;
    if(arr[middle]==n) return true;
    if(n<arr[middle]) return binarySearch(arr, n, low, middle-1);
    else return binarySearch(arr, n, middle+1, high);
}

int main() {
    vector<int> arr{3,2,5,6,7,1,23,53,74,12,43,59,11};
    sort(arr.begin(), arr.end());
    if(binarySearch(arr, 74, 0, arr.size()-1)) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;

    return 0;
}