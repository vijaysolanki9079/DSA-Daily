class Solution {
public:
    /* ------- 1 -------*/
    // static const int MOD = 1000000007;
    // vector<vector<int>> dp;

    // int power(int base, int exp) {
    //     long long res = 1;
    //     for (int i = 0; i < exp; i++) res *= base;
    //     return (res > 1e9 ? 1e9 : res); 
    // }

    // int solve(int curr, int n, int x) {
    //     if (n == 0) return 1;
    //     if (n < 0 || power(curr, x) > n) return 0; 
        
    //     if (dp[curr][n] != -1) return dp[curr][n];

    //     int include = solve(curr + 1, n - power(curr, x), x); 
    //     int exclude = solve(curr + 1, n, x);                  

    //     return dp[curr][n] = (include + exclude) % MOD;
    // }

    // int numberOfWays(int n, int x) {
    //     dp.assign(n + 2, vector<int>(n + 1, -1));
    //     return solve(1, n, x);
    // }

    /* --------- 2 ------------*/
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
