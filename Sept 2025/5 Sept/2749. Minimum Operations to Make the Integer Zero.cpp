class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long target = num1 - k * (long long)num2;
            if (target < 0) continue;
            
            int bits = __builtin_popcountll(target); // count set bits in binary
            if (bits <= k && k <= target) {
                return (int)k;
            }
        }
        return -1;
    }
};