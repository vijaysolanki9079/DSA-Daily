#include<bits/stdc++.h>
using namespace std;

/* ----- 1 -------*/
void dfs1(vector<vector<char>>& grid, int i, int j){
    int n = grid.size();  // rows
    int m = grid[0].size(); // cols 
  
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1') 
        return;
    
    grid[i][j] = true;
    
    dfs1(grid,i+1,j);
    dfs1(grid,i-1,j);
    dfs1(grid,i,j+1);
    dfs1(grid,i,j-1);
}

void noOfIslands(vector<vector<char>>& grid){
    int n = grid.size();  // rows
    int m = grid[0].size(); // cols 

    vector<vector<int>> vis(n,  false);
    
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
          if(!vis[i][j] && grid[i][j] == 1){
            count++;
            dfs1(grid, i, j);
          }
        }
    }
    return count;
}



/* -------2 --------*/
int dfs2(vector<vector<int>>& adj, int i, int j){
    int n = grid.size();
    int m = grid[0].size();

    if(i < 0 || i > n || j < 0 || j > m) return 0;

    grid[i][j] = 0; 
    int area = 1;
    area += dfs(grid,i+1,j);
    area += dfs(grid,i-1,j);
    area += dfs(grid,i,j+1);
    area += dfs(grid,i,j-1);
    
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    int maxArea = 0;
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
            if(!vis[i][j] && adj[i][j] == 1){
                maxArea = max(maxArea, dfs2(adj, i, j));
            }
        }
    }
    return maxArea;
}
