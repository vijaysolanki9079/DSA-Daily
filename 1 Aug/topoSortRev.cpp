#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topoSortKahn(int V, vector<vector<int>>& graph) {
    vector<int> inDegree(V, 0);

    // find all the in-degrees
    for (int u = 0; u < V; ++u) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

    // fill all having degree 0
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    // kahn's algo 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}
