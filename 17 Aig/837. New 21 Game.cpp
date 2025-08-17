class Solution {
public:
    /* --------- 1 --------*/
    // double bruteForceHelper(int cur, int n, int k, int maxPts) {
    //     if (cur >= k) return cur <= n ? 1.0 : 0.0;
    //     double sum = 0.0;
    //     for (int x = 1; x <= maxPts; ++x) {
    //         sum += bruteForceHelper(cur + x, n, k, maxPts);
    //     }
    //     return sum / maxPts;
    // }

    // double new21Game(int n, int k, int maxPts) {
        // if (k == 0) return 1.0;
        // return bruteForceHelper(0, n, k, maxPts);
    // }

    /* ---- 2 -----*/
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts - 1) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0;  
        double ans = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = windowSum / maxPts;
            if (i < k) {
                windowSum += dp[i];               
            } else {
                ans += dp[i];                     
            }
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];      
            }
        }
        return ans;
    }
};