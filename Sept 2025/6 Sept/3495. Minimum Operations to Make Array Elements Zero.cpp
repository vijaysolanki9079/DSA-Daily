class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ans += (getOps(r) - getOps(l - 1) + 1) / 2;
        }
        return ans;
    }
private:
    long long getOps(int n) {
        long long res = 0;
        long long ops = 0;
        for (long long p = 1; p <= n; p *= 4) {
            int left = p;
            int right = min<long long>(n, p * 4 - 1);
            ++ops;
            res += (right - left + 1) * ops;
        }
        return res;
    }
};
