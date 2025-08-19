class Solution {
public:
    /* ------ 1 ------ */
    // void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
    //     visited[node] = 1;
    //     for (auto nei : adjList[node]) {
    //         if (!visited[nei]) {
    //             dfs(nei, adjList, visited);
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();

    //     // build adjacency list
    //     vector<vector<int>> adjList(n);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (isConnected[i][j] == 1 && i != j) {
    //                 adjList[i].push_back(j);
    //             }
    //         }
    //     }

    //     vector<int> visited(n, 0);
    //     int provinces = 0;

    //     for (int i = 0; i < n; i++) {
    //         if (!visited[i]) {
    //             provinces++;
    //             dfs(i, adjList, visited);
    //         }
    //     }

    //     return provinces;
    // }

    /* ----- 2 ------*/
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};