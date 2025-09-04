class Solution {
public:
    static const int MOD = 1000000007; 

    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (long long i = 1;; ++i) {
            long long p = 1;
            for (int j = 0; j < x; ++j) p *= i;
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            for (int s = n; s >= p; --s) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }
        return dp[n];
    }
};
