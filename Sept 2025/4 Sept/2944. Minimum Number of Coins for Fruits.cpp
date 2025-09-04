class Solution {
public:
    // 1. Recursion Solution
     

    // 2. Memoization 
        // int n;
        // vector<int> dp;

        // int dfs(int i, vector<int>& prices) {
        //     if (i >= n) return 0;
        //     if (dp[i] != -1) return dp[i];

        //     int ans = INT_MAX;
        //     for (int j = i+1; j <= min(n, 2*i+2); j++) {
        //         ans = min(ans, prices[i] + dfs(j, prices));
        //     }
        //     return dp[i] = ans;
        // }

        // int minimumCoins(vector<int>& prices) {
        //     n = prices.size();
        //     dp.assign(n, -1);
        //     return dfs(0, prices);
        // }
    
    // 3. Tabulation 
        // int minimumCoins(vector<int>& prices) {
        //     int n = prices.size();
        //     vector<int> dp(n+1, 0);

        //     for (int i = n-1; i >= 0; i--) {
        //         dp[i] = INT_MAX;
        //         for (int j = i+1; j <= min(n, 2*i+2); j++) {
        //             dp[i] = min(dp[i], prices[i] + dp[j]);
        //         }
        //     }
        //     return dp[0];
        // }

    // 4. Monotonic Queue
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        deque<int> dq;

        dp[n] = 0;
        dq.push_back(n);

        for (int i = n-1; i >= 0; i--) {
            while (!dq.empty() && dq.front() > min(n, 2*i+2)) dq.pop_front();

            dp[i] = prices[i] + dp[dq.front()];
            while (!dq.empty() && dp[i] <= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};