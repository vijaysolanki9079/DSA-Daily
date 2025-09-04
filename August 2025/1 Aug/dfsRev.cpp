#include <iostream>
#include <vector>
using namespace std;

// dfs revision 
void dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &result){
    result.push_back(node);
    vis[node] = 1;
    
    for(int it=0; it<graph.size() ; ++it){
        if(!vis[it] && graph[node][it] == 1){
            dfs(it, graph, vis, result);
        }
    }
    
}

vector<int> mainFunction(int V, vector<vector<int>> &graph){
    vector<int> dfsOrder;
    vector<int> vis(V, 0);
    dfs(0, graph, vis, dfsOrder);
    
    return dfsOrder;
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    
    //convert this matrix to linked list
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
    

    vector<int> dfsResult = mainFunction(V, graph);

    cout << "\nDFS Traversal Order: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

