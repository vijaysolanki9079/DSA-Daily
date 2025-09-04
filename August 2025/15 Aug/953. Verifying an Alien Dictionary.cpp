class Solution {
public:
    /* ------ 1 ---------*/
    // bool isAlienSorted(vector<string>& words, string order) {
    //     // Map the char in order  
    //     map<char, int> ans;
    //     for (int i = 0; i < 26; ++i) {
    //         ans[order[i]] = i;
    //     }
        
    //     int first = 0, second = 1;
    //     while (second < words.size()) {  
    //         int n = words[first].length();
    //         int m = words[second].length();
    //         int bigger = (n >= m) ? m : n;

    //         bool diffFound = false; 
    //         for (int i = 0; i < bigger; ++i) {
    //             int char1 = words[first][i];
    //             int char2 = words[second][i];

    //             if (char1 == char2) continue;
                
    //             if (ans[char1] > ans[char2]) return false;
    //             diffFound = true;
    //             break; 
    //         }

    //         if (!diffFound && n > m) return false;

    //         first++, second++;
    //     } 
    //     return true;
    // }

    /* ----2 ----------*/
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> ans;
        for (int i = 0; i < 26; ++i) {
            ans[order[i]] = i;
        }

        for (int first = 0; first < words.size() - 1; ++first) {
            string &w1 = words[first];
            string &w2 = words[first + 1];
            bool different = false;

            for (int i = 0; i < min(w1.size(), w2.size()); ++i) {
                if (ans[w1[i]] < ans[w2[i]]) { 
                    different = true; 
                    break; 
                }
                if (ans[w1[i]] > ans[w2[i]]) {
                    return false;
                }
            }

            if (!different && w1.size() > w2.size()) return false;
        }

        return true;
    }
};
