#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*------- 1 --------*/
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();
        
        // Out of bounds check
        if (r < 0 || c < 0 || r >= n || c >= m) return;
        
        // Already visited or water
        if (vis[r][c] || board[r][c] != 'X') return;

        vis[r][c] = 1;

        // Explore 4 directions
        dfs(r + 1, c, board, vis);
        dfs(r - 1, c, board, vis);
        dfs(r, c + 1, board, vis);
        dfs(r, c - 1, board, vis);
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ships = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {   // <-- BUG in your code: you had `j < n` instead of `j < m`
                if (!vis[i][j] && board[i][j] == 'X') {
                    ships++;
                    dfs(i, j, board, vis);
                }
            }
        }
        return ships;
    }
};



