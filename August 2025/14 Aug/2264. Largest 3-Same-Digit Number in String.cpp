class Solution {
public:
    // string largestGoodInteger(string num) {
    //     string ans = "";
    //     for (int i = 0; i + 2 < num.size(); i++) {
    //         if (num[i] == num[i+1] && num[i] == num[i+2]) {
    //             string temp = num.substr(i, 3); 
    //             if (temp > ans) ans = temp; 
    //         }
    //     }
    //     return ans;
    // }
    string largestGoodInteger(string num) {
        char best = 0;
        int count = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i-1]) {
                count++;
                if (count >= 3) best = max(best, num[i]);
            } else {
                count = 1;
            }
        }
        return best ? string(3, best) : "";
    }
};