class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] == 0) {
                int j = i;
                while (j < n && nums[j] == 0) {
                    j++;
                }
                long long len = j - i; // length of zero block
                count += (len * (len + 1LL)) / 2; // formula
                i = j; // skip this block
            } else {
                i++;
            }
        }
        return count;
    }
};