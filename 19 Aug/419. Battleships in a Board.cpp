#include<bits/stdc++.h>
using namespace std;

Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis){
      if(r<0 ||c < 0 || r>=n || c>= m) return;
      if(vis[r][c] || board[r][c] != 'X') return;
      vis[r][c] = 1;

      // Explore 4 neighbors
        dfs(r+1, c, board);
        dfs(r-1, c, board);
        dfs(r, c+1, board);
        dfs(r, c-1, board);
    }

    int countBattleships(vector<vector<char>>& board){
      int n = board.size();
      int m = board[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
       
      int ships = 0;
      for(int i=0 ; i<n ; ++i){
        for(int i=0 ; i<n ; ++i){
            if(!visited[i][j] && board[i][j] == 'X'){
              ships++;
              dfs(i,j, board, vis);
            }
        }
      }

      return ships;
    }
};


