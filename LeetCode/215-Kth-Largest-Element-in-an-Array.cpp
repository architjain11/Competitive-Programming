class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num: nums) pq.push(num);
        k--;
        while(k--) pq.pop();
        return pq.top();
    }
};