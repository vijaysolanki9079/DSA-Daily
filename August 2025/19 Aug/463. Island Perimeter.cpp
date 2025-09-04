class Solution {
public:
    /*------  1 ----------*/
    // int islandPerimeter(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     int peri = 0;

    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < m; ++j) {
    //             if (grid[i][j] == 1) {
    //                 peri += 4;

    //                 // check up
    //                 if (i > 0 && grid[i-1][j] == 1) peri--;
    //                 // check down
    //                 if (i < n-1 && grid[i+1][j] == 1) peri--;
    //                 // check left
    //                 if (j > 0 && grid[i][j-1] == 1) peri--;
    //                 // check right
    //                 if (j < m-1 && grid[i][j+1] == 1) peri--;
    //             }
    //         }
    //     }
    //     return peri;
    // }

    /* -------- 2 ------*/
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) return 1;
        if (grid[i][j] == 0) return 1;
        if (grid[i][j] == -1) return 0;

        grid[i][j] = -1;

        return dfs(grid, i+1, j) + dfs(grid, i-1, j) +
               dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};