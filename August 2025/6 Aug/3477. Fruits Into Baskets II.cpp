class Solution {
public:
    /* ----1. Brute Force -------*/ 
    // int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    //     // [4,2,5], baskets = [3,5,4]

    //     unordered_set<int> st;
    //     int n = fruits.size();
    //     for(int i=0 ; i<n ; ++i){
    //         int num = fruits[i];
    //         for(int j=0 ; j<n ; ++j){
    //             if(st.count(j)) continue;
    //             if(num <= baskets[j]){
    //                 st.insert(j);
    //                 break;
    //             }
    //         }
    //     }    
    //     return n - st.size();
    // }

    
    /* ------better or optimal -----*/
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        vector<bool> used(m, false); // mark baskets used or not
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < m; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }

        return unplaced;
    }
};




