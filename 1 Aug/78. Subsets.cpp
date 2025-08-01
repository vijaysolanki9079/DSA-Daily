class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 1. Normal loops 
        // vector<vector<int>> subsets = {{}};
        // for (int num : nums) {
        //     int size = subsets.size();
        //     for (int i = 0; i < size; ++i) {
        //         vector<int> newSubset = subsets[i];
        //         newSubset.push_back(num);
        //         subsets.push_back(newSubset);
        //     }
        // }

        // return subsets;

        // 2. Bit Manipulation 
        int n = nums.size();
        int total = 1 << n; // 2^n subsets

        vector<vector<int>> subsets;
        for (int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};