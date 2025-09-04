class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        // Find the first occurrence of '6' from left
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';  // Change it to '9'
                break;       // Only change one digit
            }
        }
        
        return stoi(s);
    }
};