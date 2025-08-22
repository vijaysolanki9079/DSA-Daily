class Solution {
public:
    /* ------- 1 Brute Force (slow) ------- */
    // int numSubmat(vector<vector<int>>& mat) {
    //     int m = mat.size(), n = mat[0].size();
    //     int ans = 0;

    //     for (int i1 = 0; i1 < m; i1++) {
    //         for (int j1 = 0; j1 < n; j1++) {
    //             for (int i2 = i1; i2 < m; i2++) {
    //                 for (int j2 = j1; j2 < n; j2++) {
    //                     bool allOnes = true;
    //                     for (int x = i1; x <= i2 && allOnes; x++) {
    //                         for (int y = j1; y <= j2; y++) {
    //                             if (mat[x][y] == 0) {
    //                                 allOnes = false;
    //                                 break;
    //                             }
    //                         }
    //                     }
    //                     if (allOnes) ans++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    /* ------- 2 ------ */
    // int numSubmat(vector<vector<int>>& mat) {
    //     int m = mat.size(), n = mat[0].size();
    //     vector<vector<int>> height(m, vector<int>(n, 0));
        
    //     // Build height matrix
    //     for (int j = 0; j < n; j++) {
    //         for (int i = 0; i < m; i++) {
    //             if (mat[i][j] == 1) {
    //                 height[i][j] = (i == 0 ? 1 : height[i-1][j] + 1);
    //             }
    //         }
    //     }
        
    //     int ans = 0;
    //     // Process each row as histogram
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             int minHeight = height[i][j];
    //             for (int k = j; k >= 0 && minHeight > 0; k--) {
    //                 minHeight = min(minHeight, height[i][k]);
    //                 ans += minHeight;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    /* ----- 3 (mono-tonic stack) ------ */
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            stack<int> st;
            vector<int> sum(n, 0);

            for (int j = 0; j < n; j++) {
                while (!st.empty() && height[st.top()] >= height[j])
                    st.pop();

                if (!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + height[j] * (j - prev);
                } else {
                    sum[j] = height[j] * (j + 1);
                }

                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};