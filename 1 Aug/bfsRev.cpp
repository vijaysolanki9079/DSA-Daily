#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// BFS traversal 
vector<int> bfsTraversal(int V, vector<vector<int>> &adjList){
    vector<int> bfsResult;
    queue<int> q;
    vector<int> vis(V, 0); 

    vis[0] = 1;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);

        for(int it : adjList[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfsResult;
}

int main(){
    int V = 5;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adjList(V);
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(graph[i][j] == 1){
                adjList[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < V; ++i){
        cout << "Node " << i << ": ";
        for(int neighbor : adjList[i]){
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // Call BFS
    vector<int> ans = bfsTraversal(V, adjList);
    
    cout << "BFS Traversal: ";
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
