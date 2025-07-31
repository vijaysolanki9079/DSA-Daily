class Solution {
public:
    /* ---------- Brute force ------*/
    // int longestSubarray(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxAnd = 0;

    //     for (int i = 0; i < n; i++) {
    //         int curr = nums[i];
    //         for (int j = i; j < n; j++) {
    //             curr &= nums[j];
    //             maxAnd = max(maxAnd, curr);
    //         }
    //     }

    //     int maxLen = 0;
    //     for (int i = 0; i < n; i++) {
    //         int curr = nums[i];
    //         for (int j = i; j < n; j++) {
    //             curr &= nums[j];
    //             if (curr == maxAnd)
    //                 maxLen = max(maxLen, j - i + 1);
    //         }
    //     }

    //     return maxLen;
    // }

    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int longest = 0, count = 0;

        for (int num : nums) {
            if (num == maxVal) {
                count++;
                longest = max(longest, count);
            } else {
                count = 0; // reset if not maxVal
            }
        }

        return longest;
    }

    
};
