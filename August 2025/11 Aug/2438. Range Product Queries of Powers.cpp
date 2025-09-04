class Solution {
public:
    /* ----- 1 ------*/
    // vector<int> productQueries(int n, vector<vector<int>>& queries) {
    //     vector<int> power;
    //     for (int bit = 0; n > 0; ++bit) {
    //         if (n & 1) {
    //             power.push_back(1 << bit);
    //         }
    //         n >>= 1;
    //     }
 
    //     const int MOD = 1e9 + 7;
    //     vector<int> ans;

    //     for (auto &q : queries) {
    //         long long mul = 1;
    //         for (int j = q[0]; j <= q[1]; ++j) {
    //             mul = (mul * power[j]) % MOD;
    //         }
    //         ans.push_back(mul);
    //     }
    //     return ans;


        /* ------ 2 ------

        Optimized Approach :- 
            Idea:
                1. Decompose n into powers of two from its binary form (like before).
                2. Create a prefix array where:
                    prefix[i]=(power[0] × power[1] ×.........× power[i] ) modM
                3. For query (l, r):
                    product =( prefix[r] / prefix[l−1] ) * (mod M)
        */
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        // make the power list
        for (int bit = 0; n > 0; ++bit) {
            if (n & 1) {
                power.push_back(1 << bit);
            }
            n >>= 1;
        }

        // make a Prefix pdt array
        vector<long long> prefix(power.size());
        prefix[0] = power[0] % MOD;
        for (int i = 1; i < power.size(); ++i) {
            prefix[i] = (prefix[i - 1] * power[i]) % MOD;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long result = prefix[r];
            if (l > 0) {
                result = (result * modPow(prefix[l - 1], MOD - 2)) % MOD;
            }
            ans.push_back((int)result);
        }

        return ans;
    }
};
