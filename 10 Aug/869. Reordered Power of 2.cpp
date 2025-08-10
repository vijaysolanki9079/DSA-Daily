class Solution {
public:
    // bool isPowerOfTwo(int n) {
    //     if (n <= 0) return false;
    //     return (n & (n - 1)) == 0;
    // }

    // bool reorderedPowerOf2(int n) {
    //     string s = to_string(n);
    //     sort(s.begin(), s.end()); 

    //     do {
    //         if (s[0] == '0') continue; 
    //         int num = stoi(s);
    //         if (isPowerOfTwo(num)) return true;
    //     } while (next_permutation(s.begin(), s.end()));

    //     return false;
    // }

    /* -------- 2 ----------*/
    bool reorderedPowerOf2(int n) {
        string s = sortDigits(n);

        for(int i = 0; i<31; i++){
            int power = 1 << i;
            if(s == sortDigits(power)){
                return true;
            }
        }
        return false;
    }

    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};