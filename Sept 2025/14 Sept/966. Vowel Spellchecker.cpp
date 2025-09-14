class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap, vowelMap;

        auto devowel = [](const string& s) {
            string t = s;
            for (auto& c : t) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    c = '*';
                else
                    c = lower;
            }
            return t;
        };

        for (auto &w : wordlist) {
            string lower;
            for (char c : w) lower += tolower(c);
            if (!caseMap.count(lower)) caseMap[lower] = w;

            string dv = devowel(w);
            if (!vowelMap.count(dv)) vowelMap[dv] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower;
            for (char c : q) lower += tolower(c);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            string dv = devowel(q);
            if (vowelMap.count(dv)) {
                ans.push_back(vowelMap[dv]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
