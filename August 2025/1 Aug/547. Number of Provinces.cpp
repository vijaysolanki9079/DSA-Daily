class Solution {
    void dfs(int node, vector<int> adjLs[], vector<int> &vis){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it , adjLs, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjLs[V];

        //to change adjacency matrix to list
        for(int i=0 ; i<V ; i++){
            for(int j=0; j<V ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        // iterating for all the elemnts...as its not imp that every element is 
        // connected to each other 
        vector<int> vis(V, 0);
        int cnt = 0;
        for(int i=0; i<V ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i , adjLs , vis);
            }
        }
        return cnt;
    }
};