class Solution {
public:
    // 2. Memoization --> O(n^2)
    // int solve(int i, int j, vector<vector<int>>& a,vector<vector<int>>& dp){
    //     int n = a.size();
    //     if( i == n-1) return a[i][j]; // base case i.e. last row
    //     if (dp[i][j] != -1) return dp[i][j];

    //     // two cases - down or diagonal  
    //     int down = solve(i + 1, j, a, dp);
    //     int downRight = solve(i + 1, j + 1, a, dp);

    //     return dp[i][j] = a[i][j] + min(down, downRight);
    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1)); 
    //     return solve(0, 0, triangle, dp);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
                
        return dp[0];
    }
};