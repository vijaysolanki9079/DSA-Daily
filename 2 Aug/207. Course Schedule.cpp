class Solution {
public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /* ------- Wrong Solution (technique) -------*/
        // int n = prerequisites.size();
        // unordered_map<int, int> mp;       // courseNo. , -Took / -NotTook(0/1)  

        // for(int i=0; i<n ; ++i){
        //     if(numCourses == 0) return false;
        //     int it = prerequisites[i];
            
        //     if(mp.count(it[1])){
        //         if(mp.count(it[0])    
        //             continue;
        //         numCourses--;
        //     } else {
        //         numCourses--;
        //         if(mp.count(it[0])    
        //             continue;
        //         numCourses--;        
        //     }
        // }
        // return true;



        /* ------ 2 (Kahn's Algorithm) ---------*/ 
        // Have to do -> Topological Sorting
    //     vector<vector<int>> adj(numCourses);
    //     vector<int> inDegree(numCourses, 0);

    //     for (auto& pre : prerequisites) {
    //         adj[pre[1]].push_back(pre[0]);  // b → a
    //         inDegree[pre[0]]++;
    //     }

    //     queue<int> q;
    //     for (int i = 0; i < numCourses; ++i) {
    //         if (inDegree[i] == 0)
    //             q.push(i);
    //     }

    //     int count = 0;
    //     while (!q.empty()) {
    //         int course = q.front();
    //         q.pop();
    //         count++;

    //         for (int neighbor : adj[course]) {
    //             inDegree[neighbor]--;
    //             if (inDegree[neighbor] == 0)
    //                 q.push(neighbor);
    //         }
    //     }

    //     return count == numCourses;  
    // }

    /*-------- 3 (DFS with Cycle Detection) -------*/
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[node] == 1) return false; 
        if (visited[node] == 2) return true;  

        visited[node] = 1;
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, visited)) return false;
        }
        visited[node] = 2; 
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites)
            graph[p[1]].push_back(p[0]); 

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, visited))
                return false;
        }
        return true;
    }
};           