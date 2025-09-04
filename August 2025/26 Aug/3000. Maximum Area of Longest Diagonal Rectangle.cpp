class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiag = -1;  // to store max diagonal length squared
        int maxArea = 0;         // to store max area for that diagonal

        for (auto &rect : dimensions) {
            long long l = rect[0];
            long long w = rect[1];

            long long diag = l * l + w * w;  // diagonal squared
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
