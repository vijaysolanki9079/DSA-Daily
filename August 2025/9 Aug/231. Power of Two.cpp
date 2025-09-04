class Solution {
public:
    bool isPowerOfTwo(int n) {
        // what are the contraints to have number i.e. the power of 2 .....
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};