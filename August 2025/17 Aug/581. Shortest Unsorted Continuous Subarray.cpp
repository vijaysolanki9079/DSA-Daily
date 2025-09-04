class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -2; 
        int mn = nums[n-1], mx = nums[0];
        
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            if (nums[i] < mx) end = i;
        }
        
        for (int i = n-2; i >= 0; --i) {
            mn = min(mn, nums[i]);
            if (nums[i] > mn) start = i;
        }
        
        return end - start + 1;
    }
};