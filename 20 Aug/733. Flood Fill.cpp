class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& arr, vector<vector<int>>& image, int newColor, int delRow[],
            int delCol[], int iniColor) {
        arr[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                image[nrow][ncol] == iniColor && arr[nrow][ncol] != newColor) {
                dfs(nrow, ncol, arr, image, newColor, delRow, delCol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> arr = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, arr, image, color, delRow, delCol, iniColor);
        return arr;
    }
};