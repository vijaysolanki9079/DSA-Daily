class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        // make the adjList and the inDegree list for it 
        for(auto &pre : prerequisites){
            adjList[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        // if inDegree == 0 ..wala work 
        for(int i=0 ; i<inDegree.size() ; ++i){
            if(inDegree[i] == 0)
                q.push(i); 
        }           

        vector<int> ans;
        int count = 0;

        // now queue main operation
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            count++;

            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        if(count == numCourses)
            return ans;
        
        return {};
    }
};