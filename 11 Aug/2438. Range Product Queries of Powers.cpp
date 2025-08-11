class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        for (int bit = 0; n > 0; ++bit) {
            if (n & 1) {
                power.push_back(1 << bit);
            }
            n >>= 1;
        }
 
        const int MOD = 1e9 + 7;
        vector<int> ans;

        for (auto &q : queries) {
            long long mul = 1;
            for (int j = q[0]; j <= q[1]; ++j) {
                mul = (mul * power[j]) % MOD;
            }
            ans.push_back(mul);
        }
        return ans;
    }
};
