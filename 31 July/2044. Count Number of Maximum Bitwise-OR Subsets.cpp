class Solution {
public:
    /* --------- 1 --------*/ 
    // bool check(vector<int>& arr, int result){
    //     int res = 0;
    //     for(int j = 0; j < arr.size(); ++j){
    //         res |= arr[j];
    //     }
    //     return res == result;
    // }

    // int checkOr(vector<int>& arr) {
    //     int res = 0;
    //     for (int val : arr) res |= val;
    //     return res;
    // }

    /*   ----- main function ----*/
    // int countMaxOrSubsets(vector<int>& nums) {
        // int result = 0;
        // for(int i = 0; i < nums.size(); ++i) {
        //     result |= nums[i];
        // }

        // int n = nums.size();
        // int total = 1 << n; // 2^n subsets
        // int countNum = 0;


        // 1.....counting each time 
        // for (int mask = 0; mask < total; ++mask) {
        //     vector<int> check;  // ✅ declared here once per subset
        //     for (int i = 0; i < n; ++i) {
        //         if (mask & (1 << i)) {
        //             check.push_back(nums[i]);
        //         }
        //     }
        //     if (check.size() > 0 && checkOr(check) == result) {
        //         countNum++;
        //     }
        // }


        // 2.....   Masking 
        // for (int mask = 0; mask < total; ++mask) {
        //     int orValue = 0;
        //     for (int i = 0; i < n; ++i) {
        //         if (mask & (1 << i)) {
        //             orValue |= nums[i];
        //         }
        //     }
        //     if (orValue == result) countNum++;
        // }

        // return countNum;
    // }
// };

    int maxOr = 0;
    int count = 0;

    void backtrack(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr > maxOr) {
                maxOr = currentOr;
                count = 1;
            } else if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        backtrack(nums, index + 1, currentOr | nums[index]);
        backtrack(nums, index + 1, currentOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        backtrack(nums, 0, 0); // {nums, index, currentOr}
        return count;
    }
};