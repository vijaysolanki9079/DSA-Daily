class Solution {
public:
    /* -------- 1 ------*/
    // string removeDigit(string number, char digit) {
    //     string maxStr = "0";
    //     for (int i = 0; i < number.size(); ++i) {
    //         if (number[i] == digit) {
    //             string str = number;
    //             str.erase(i, 1); 
    //             if (str > maxStr) {
    //                 maxStr = str;
    //             }
    //         }
    //     }
    //     return maxStr;
    // }

    /* ---------- 2 --------------*/
    string removeDigit(string number, char digit) {
        int n = number.size();
        int idx = -1;

        for (int i = 0; i < n; ++i) {
            if (number[i] == digit) {
                idx = i; // store last seen digit 
                if (i + 1 < n && number[i] < number[i + 1]) {
                    // greedily delete to get larger number
                    number.erase(i, 1);
                    return number;
                }
            }
        }

        // if no better greedy position found, delete the last occurrence
        number.erase(idx, 1);
        return number;
    }


};
