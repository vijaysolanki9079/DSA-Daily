//  [ [1 , 0] , [1 , 2] , [1 , 3] ]
// 0 -> 1 , 1 ->  * , 2->  1 , 3 -> 1 ... 
class Solution {
public:
    /* ------ 1 (TLE)--------*/
    // int dfs(int node, int parent, vector<vector<int>>& adjList) {
    //     int height = 0;
    //     for (int neighbor : adjList[node]) {
    //         if (neighbor != parent) {
    //             height = max(height, dfs(neighbor, node, adjList));
    //         }
    //     }
    //     return height + 1; 
    // }

    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     if (n == 1) return {0};

    //     // make adjList
    //     vector<vector<int>> adjList(n);
    //     for (auto& e : edges) {
    //         adjList[e[0]].push_back(e[1]);
    //         adjList[e[1]].push_back(e[0]);
    //     }

    //     // count minHeight
    //     int minHeight = INT_MAX;
    //     vector<int> result;

    //     for (int i = 0; i < n; ++i) {
    //         int h = dfs(i, -1, adjList);
    //         if (h < minHeight) {
    //             minHeight = h;
    //             result = {i};
    //         } else if (h == minHeight) {
    //             result.push_back(i);
    //         }
    //     }

    //     return result;
    // }

    /* ---------2 (using Topo Sort concept)------*/
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i);
        }

        vector<int> res;
        while (!q.empty()) {
            int sz = q.size();
            res.clear(); 
            for (int i = 0; i < sz; ++i) {
                int node = q.front(); q.pop();
                res.push_back(node);
                for (int nei : adjList[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) q.push(nei);
                }
            }
        }
        return res;
    }
};  
