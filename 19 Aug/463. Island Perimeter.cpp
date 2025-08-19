#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int peri = 0;

        // Approach - check all the direction for each i.e. Element = 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    peri += 4;

                    // check up
                    if (i > 0 && grid[i-1][j] == 1) peri--;
                    // check down
                    if (i < n-1 && grid[i+1][j] == 1) peri--;
                    // check left
                    if (j > 0 && grid[i][j-1] == 1) peri--;
                    // check right
                    if (j < m-1 && grid[i][j+1] == 1) peri--;
                }
            }
        }
        return peri;
    }
};