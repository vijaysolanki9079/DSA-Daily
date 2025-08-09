class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int maxEle = *max_element(nums.begin(), nums.end());

        for(int i=0 ; i<nums.size() ; ++i){
            if(nums[i] == maxEle){
                continue;
            } else {
                moves += abs(nums[i] - maxEle);
            }
        } 

        return moves;

    }
};