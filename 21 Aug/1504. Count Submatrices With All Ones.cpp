class Solution {
public:
    /* ------- 1 Brute Force (slow) ------- */
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;

        for (int i1 = 0; i1 < m; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int i2 = i1; i2 < m; i2++) {
                    for (int j2 = j1; j2 < n; j2++) {
                        bool allOnes = true;
                        for (int x = i1; x <= i2 && allOnes; x++) {
                            for (int y = j1; y <= j2; y++) {
                                if (mat[x][y] == 0) {
                                    allOnes = false;
                                    break;
                                }
                            }
                        }
                        if (allOnes) ans++;
                    }
                }
            }
        }
        return ans;
    }
};