class Solution {
public:
    /*
    // see break the steps into problems
    1. see first mark all the  X marked in the result array  ...ok
    2. now take a diff array / map / set ..........to store O marked
    3. iterate the first O marked ---> now find the no.s is connected to
    different no. or not by the all direction method ....and have to go one
    after the other and mark X backtracking ok.......use a bfs/dfs approach for
    this
    4. all done
    */
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = 'T'; // Temporarily mark the cell as safe
        dfs(board, i + 1, j, m, n);
        dfs(board, i - 1, j, m, n);
        dfs(board, i, j + 1, m, n);
        dfs(board, i, j - 1, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();    // i
        int n = board[0].size(); // j

        // Step 1: Start DFS from the boundary cells
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, m, n); // Left boundary
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1, m, n); // Right boundary
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j, m, n); // Top boundary
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j, m, n); // Bottom boundary
        }

        // Step 2: Flip all surrounded 'O's to 'X' and restore the safe ones
        // marked as 'T' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X'; // Captured region
                else if (board[i][j] == 'T')
                    board[i][j] = 'O'; // Restore safe region
            }
        }
    }
};

