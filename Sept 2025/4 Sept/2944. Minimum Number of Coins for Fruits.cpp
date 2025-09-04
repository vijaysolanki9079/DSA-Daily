class Solution {
public:
    // 1. Recursion Solution
     

    // 2. Memoization 
        int n;
        vector<int> dp;

        int dfs(int i, vector<int>& prices) {
            if (i >= n) return 0;
            if (dp[i] != -1) return dp[i];

            int ans = INT_MAX;
            for (int j = i+1; j <= min(n, 2*i+2); j++) {
                ans = min(ans, prices[i] + dfs(j, prices));
            }
            return dp[i] = ans;
        }

        int minimumCoins(vector<int>& prices) {
            n = prices.size();
            dp.assign(n, -1);
            return dfs(0, prices);
        }

};