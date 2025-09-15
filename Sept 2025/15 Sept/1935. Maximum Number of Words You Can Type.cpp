class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        istringstream ss(text);
        string w;
        int cnt = 0;
        while (ss >> w) {
            bool ok = true;
            for (char c : w) if (broken.count(c)) { ok = false; break; }
            if (ok) ++cnt;
        }
        return cnt;
    }
};