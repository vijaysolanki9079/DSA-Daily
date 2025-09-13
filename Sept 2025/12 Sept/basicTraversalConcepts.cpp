#include<bits/stdc++.h>
using namespace std;

// 1
void bfs(vector<vector<int>> &adj, int start){
    int n = adj.size();
    vector<bool> vis(n, false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
          if(!vis[v]) {
              vis[v] = true;
              q.push(v);
          }
        }
    }
}

// 2 
dfsMain(int node, vector<vector<int>>& adj, vector<int> &vis){
    vis[u]=true;
    for(int v:adj[u]){
        if(!vis[v]) dfsMain(v,adj,vis);
    }
}

void dfs(int n, vector<vector<int>>& adj){
    vector<bool> vis(n, false);
    dfsMain(0, adj, vis);

}



int main(){

}
 