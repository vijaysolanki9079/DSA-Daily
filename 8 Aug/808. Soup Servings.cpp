class Solution {
public:
    /* ------ DP(memoization) --------------*/
    vector<vector<double>> memo;
    double helper(int a, int b) {
        // base cases 
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (memo[a][b] >= 0) return memo[a][b];

        // going to calulate the probabilty of each cases
        memo[a][b] = 0.25 * (
            helper(a - 4, b) +
            helper(a - 3, b - 1) +
            helper(a - 2, b - 2) +
            helper(a - 1, b - 3)
        );

        return memo[a][b];
    }

    double soupServings(int n) {
        // scale the n 
        int N = (n + 24) / 25;
        memo = vector<vector<double>>(N + 1, vector<double>(N + 1, -1.0));
        return helper(N, N);
    }
};