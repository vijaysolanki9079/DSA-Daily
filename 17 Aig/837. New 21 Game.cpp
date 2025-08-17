class Solution {
public:
    double bruteForceHelper(int cur, int n, int k, int maxPts) {
        if (cur >= k) return cur <= n ? 1.0 : 0.0;
        double sum = 0.0;
        for (int x = 1; x <= maxPts; ++x) {
            sum += bruteForceHelper(cur + x, n, k, maxPts);
        }
        return sum / maxPts;
    }

    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        return bruteForceHelper(0, n, k, maxPts);
    }
};