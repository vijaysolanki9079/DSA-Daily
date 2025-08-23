class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;
        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] = rowMasks[row] | 1 << (col - 2);
            }
        }

        int result = 0;
        // Define bitmasks for left, middle, and right seat blocks
        int leftMask   = 15;   // seats 2,3,4,5
        int middleMask = 60;   // seats 4,5,6,7
        int rightMask  = 240;   // seats 6,7,8,9

        for (auto& [row, mask] : rowMasks) {
            bool left   = (mask & leftMask) == 0;
            bool right  = (mask & rightMask) == 0;
            bool middle = (mask & middleMask) == 0;

            if (left && right) result += 2;
            else if (left || right || middle) result += 1;
            // else result += 0
        }

        result += (n - rowMasks.size()) * 2;

        return result;
    }
};