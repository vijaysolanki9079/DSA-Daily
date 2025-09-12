class Solution {
public:
    bool doesAliceWin(string s) {
        int index = 0;
        int lengthCut = 0;

        while (index < s.size()) {
            char ch = s[index];
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
                lengthCut++;
            } 
            index++;
        }

        return lengthCut > 0;  
    }
};
