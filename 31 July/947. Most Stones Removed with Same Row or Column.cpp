class Solution {
public:
    // 1. 
    // int removeStones(vector<vector<int>>& stones){
    //     int n = stones.size();
        
    //     // sort(stones.begin(), stones.end());
        
    //     //  [0,0]  ,   [0,1]  ,  [1,0]  ,  [1,2]  ,  [2,1]  ,  [2,2]
    //     int cnt = 0;
    //     for (int i=n-1; i>=0; i--){
    //         int first = stones[i][0];
    //         int second = stones[i][1];
            
    //         for(int j=i-1 ; j>=0 ; j--){
    //             int nextFirst = stones[j][0];
    //             int nextSecond = stones[j][1];
                
    //             if(first == nextFirst){
    //                 cnt++;
    //             } else if(second == nextSecond){
    //                 cnt++;
    //                 break;
    //             }
    //         }
    //     }
    //     return cnt;
    // }


    /* ------- 2 ------*/ 
    vector<int> parent;
    vector<int> rank;
    int n;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if(root_i != root_j) {
            if(rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else  if(rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_j] = root_i;
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    Union(i, j);
            }
        }
        
        int groups = 0;
        for(int i = 0; i<n; i++) {
            if(parent[i] == i) groups++;
        }
        
        return n-groups;
    }
};