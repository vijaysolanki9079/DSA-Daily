class Solution {
public:
    /* ------- 1 ---------
    Time: O(V + E)
    Space: O(V)               */ 
    
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<int> color(n, -1); // -1: uncolored

    //     for (int i = 0; i < n; ++i) {
    //         if (color[i] == -1) {
    //             queue<int> q;
    //             q.push(i);
    //             color[i] = 0;

    //             while (!q.empty()) {
    //                 int node = q.front(); q.pop();
    //                 for (int neighbor : graph[node]) {
    //                     if (color[neighbor] == -1) {
    //                         color[neighbor] = 1 - color[node];
    //                         q.push(neighbor);
    //                     } else if (color[neighbor] == color[node]) {
    //                         return false;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return true;
    // }

    /* ------ 2 --------*/ 
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int c) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, graph, color, 1 - c))
                    return false;
            } else if (color[neighbor] == c) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!dfs(i, graph, color, 0))
                    return false;
            }
        }
        return true;
    }
};
 
