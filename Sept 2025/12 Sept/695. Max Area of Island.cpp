class Solution {
public:
    // int dfs(vector<vector<int>>& grid, int i, int j){
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) 
    //         return 0;
        
    //     grid[i][j] = 0; 
    //     int area = 1;

    //     area += dfs(grid,i+1,j);
    //     area += dfs(grid,i-1,j);
    //     area += dfs(grid,i,j+1);
    //     area += dfs(grid,i,j-1);

    //     return area;
    // }

    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
        
    //     int ans = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]==1){
    //                 ans = max(ans,dfs(grid,i,j));
    //             }
    //         }
    //     }

    //     return ans;
    // }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty()){
                        auto [x,y]=q.front();q.pop();
                        area++;
                        for(auto [dx,dy]:dirs){
                            int nx=x+dx,ny=y+dy;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                                grid[nx][ny]=0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};

    