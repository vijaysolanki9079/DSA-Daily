class Solution {
public:
    // int integerBreak(int n) {
    //     vector<int> dp(n+1, 0);

    //     dp[1] = 0;  
    //     for (int i = 2; i <= n; i++) {
    //         for (int j = 1; j < i; j++) {

    //             // case1: split into two
    //             int noSplit = j * (i - j);

    //             // case2: split further 
    //             int split = j * dp[i - j];

    //             dp[i] = max(dp[i], max(noSplit, split));
    //         }
    //     }

    //     return dp[n];
    // }

    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        return product * n;
    }
};