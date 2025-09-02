class Solution {
public:
     int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        if (n == 0) return 0;
        
        vector<int> maxPrizesLeft(n, 0);
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            
            int currentPrizes = right - left + 1;
            maxPrizesLeft[right] = (right > 0) ? max(maxPrizesLeft[right-1], currentPrizes) : currentPrizes;
        }
        
        int maxTotal = 0;
        left = 0;
        
        for (int right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            
            int currentSegmentPrizes = right - left + 1;
            int bestFirstSegment = (left > 0) ? maxPrizesLeft[left - 1] : 0;
            
            maxTotal = max(maxTotal, currentSegmentPrizes + bestFirstSegment);
        }
        
        return maxTotal;
    }
};