class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        vector<int> ans;
        auto it=find(arr.begin(), arr.end(), x);
        int n=arr.size();
        int left=0, right=n-1;
        if(it!=arr.end()) {
            left=it-arr.begin();
            right=left+1;
        }
        else if(arr[0]<=x && arr[n-1]>=x) {
            for(int i=0; i<n; i++) {
                if(arr[i]>x) {
                    left=i-1;
                    right=i;
                    break;
                }
            }
        }
        else if(x<arr[0]) right=left+1;
        else left=right-1;
        
        while(k--) {
            if(left>=0 && right<=n-1) {
                if(abs(arr[right]-x)<abs(arr[left]-x)) {
                    ans.push_back(arr[right]);
                    right++;
                }
                else {
                    ans.push_back(arr[left]);
                    left--;
                }
            }
            else {
                if(left<0) {
                    ans.push_back(arr[right]);
                    right++;
                }
                else {
                    ans.push_back(arr[left]);
                    left--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};