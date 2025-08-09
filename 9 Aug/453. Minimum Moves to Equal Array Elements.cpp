class Solution {
public:
    int minMoves(vector<int>& nums) {
        /* ----- 1 (wring answer) -------*/
        // int moves = 0;
        // int maxEle = *max_element(nums.begin(), nums.end());

        // for(int i=0 ; i<nums.size() ; ++i){
        //     if(nums[i] == maxEle){
        //         continue;
        //     } else {
        //         moves += abs(nums[i] - maxEle);
        //     }
        // } 

        // return moves;


        /* ------ 2 ------*/
        long long sum = 0;
        int minEle = INT_MAX;

        for (int num : nums) {
            sum += num;
            minEle = min(minEle, num);
        }
        return sum - (long long)minEle * nums.size(); 
    }
};