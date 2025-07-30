class Solution {
public:
    /* ---------1 ---------*/
    // vector<int> smallestSubarrays(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans(n);

    //     for (int i = 0; i < n; i++) {
    //         int currentOr = 0;
    //         for (int j = i; j < n; j++) {
    //             currentOr |= nums[j];
    //             if (currentOr == getMaxORFromIndex(nums, i)) {
    //                 ans[i] = j - i + 1;
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // int getMaxORFromIndex(vector<int>& nums, int start) {
    //     int res = 0;
    //     for (int i = start; i < nums.size(); i++) {
    //         res |= nums[i];
    //     }
    //     return res;
    // }
    

    /* ------ 2 -----------*/
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> lastSeen(32, -1); // last index each bit was seen

        for (int i = n - 1; i >= 0; --i) {
            // update last seen positions of bits in nums[i]
            for (int bit = 0; bit < 32; ++bit) {
                if (nums[i] & (1 << bit)) {
                    lastSeen[bit] = i;
                }
            }

            // the farthest we must go to include all current OR bits
            int farthest = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeen[bit] != -1) {
                    farthest = max(farthest, lastSeen[bit]);
                }
            }

            ans[i] = farthest - i + 1;
        }

        return ans;
    }
};
