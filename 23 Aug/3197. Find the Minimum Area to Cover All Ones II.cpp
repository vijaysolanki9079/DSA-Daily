class Solution {
public:
    /* ---------1 ---------------- */
    // int minimumSum(vector<vector<int>>& grid) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<pair<int,int>> ones;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (grid[i][j] == 1) ones.push_back({i,j});
    //         }
    //     }
    //     int k = ones.size();
    //     int ans = INT_MAX;

    //     // Assign each "1" to one of 3 groups (3^k possibilities, so prune for big k)
    //     function<void(int, vector<vector<pair<int,int>>>&)> dfs = [&](int idx, vector<vector<pair<int,int>>>& groups) {
    //         if (idx == k) {
    //             // All assigned → compute area sum
    //             int sum = 0;
    //             for (int g = 0; g < 3; g++) {
    //                 if (groups[g].empty()) return; // all groups must have 1s
    //                 int minr = INT_MAX, maxr = INT_MIN;
    //                 int minc = INT_MAX, maxc = INT_MIN;
    //                 for (auto &p : groups[g]) {
    //                     minr = min(minr, p.first);
    //                     maxr = max(maxr, p.first);
    //                     minc = min(minc, p.second);
    //                     maxc = max(maxc, p.second);
    //                 }
    //                 sum += (maxr - minr + 1) * (maxc - minc + 1);
    //             }
    //             ans = min(ans, sum);
    //             return;
    //         }
    //         for (int g = 0; g < 3; g++) {
    //             groups[g].push_back(ones[idx]);
    //             dfs(idx+1, groups);
    //             groups[g].pop_back();
    //         }
    //     };

    //     vector<vector<pair<int,int>>> groups(3);
    //     dfs(0, groups);

    //     return ans;
    // }


    /* ----- 2-------*/
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = INT_MAX;
        
        // Helper function to get bounding box area for a region
        auto getBox = [&](int r1, int r2, int c1, int c2) -> int {
            int minr = INT_MAX, maxr = INT_MIN;
            int minc = INT_MAX, maxc = INT_MIN;
            bool found = false;
            
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j] == 1) {
                        found = true;
                        minr = min(minr, i);
                        maxr = max(maxr, i);
                        minc = min(minc, j);
                        maxc = max(maxc, j);
                    }
                }
            }
            
            if (!found) return -1; // No 1s in this region
            return (maxr - minr + 1) * (maxc - minc + 1);
        };
        
        // Pattern 1: Three horizontal strips (---)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int area1 = getBox(0, i, 0, m - 1);           // Top strip
                int area2 = getBox(i + 1, j, 0, m - 1);       // Middle strip  
                int area3 = getBox(j + 1, n - 1, 0, m - 1);   // Bottom strip
                
                if (area1 != -1 && area2 != -1 && area3 != -1) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 2: Three vertical strips (|||)
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                int area1 = getBox(0, n - 1, 0, i);           // Left strip
                int area2 = getBox(0, n - 1, i + 1, j);       // Middle strip
                int area3 = getBox(0, n - 1, j + 1, m - 1);   // Right strip
                
                if (area1 != -1 && area2 != -1 && area3 != -1) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 3: Top horizontal + bottom split vertically (T shape upside down)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int area1 = getBox(0, i, 0, m - 1);              // Top rectangle
                int area2 = getBox(i + 1, n - 1, 0, j);          // Bottom left
                int area3 = getBox(i + 1, n - 1, j + 1, m - 1);  // Bottom right
                
                if (area1 != -1 && area2 != -1 && area3 != -1) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 4: Bottom horizontal + top split vertically (T shape)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                int area1 = getBox(0, i - 1, 0, j);             // Top left
                int area2 = getBox(0, i - 1, j + 1, m - 1);     // Top right
                int area3 = getBox(i, n - 1, 0, m - 1);         // Bottom rectangle
                
                if (area1 != -1 && area2 != -1 && area3 != -1) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 5: Left vertical + right split horizontally (⊢ shape)
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n - 1; i++) {
                int area1 = getBox(0, n - 1, 0, j);             // Left rectangle
                int area2 = getBox(0, i, j + 1, m - 1);         // Right top
                int area3 = getBox(i + 1, n - 1, j + 1, m - 1); // Right bottom
                
                if (area1 != -1 && area2 != -1 && area3 != -1) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 6: Right vertical + left split horizontally (⊣ shape)
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n - 1; i++) {
                int area1 = getBox(0, i, 0, j - 1);             // Left top
                int area2 = getBox(i + 1, n - 1, 0, j - 1);     // Left bottom
                int area3 = getBox(0, n - 1, j, m - 1);         // Right rectangle
                
                if (area1 != -1 && area2 != -1 && area3 != -1) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans; // Return -1 if no valid split found
    }
};