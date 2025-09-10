class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> know(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) know[i + 1].insert(l);
        }
        unordered_set<int> needTeach;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int l : know[u]) {
                if (know[v].count(l)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        if (needTeach.empty()) return 0;
        vector<int> cnt(n + 1, 0);
        for (int p : needTeach) {
            for (int l = 1; l <= n; l++) {
                if (know[p].count(l)) continue;
                cnt[l]++;
            }
        }
        int res = INT_MAX;
        for (int l = 1; l <= n; l++) {
            int teach = 0;
            for (int p : needTeach) {
                if (!know[p].count(l)) teach++;
            }
            res = min(res, teach);
        }
        return res;
    }
};
