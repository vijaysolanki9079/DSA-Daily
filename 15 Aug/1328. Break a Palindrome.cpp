class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";

        // Try changing first non-'a' in the first half
        for (int i = 0; i < n / 2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // If all first-half chars are 'a', change last char to 'b'
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
