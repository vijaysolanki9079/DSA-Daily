class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        /*  -------- 1 --------*/
        // int n = properties.size();
        // int cnt = 0;

        // for(auto it : properties){
        //     int first = it[0];
        //     int second = it[1];

        //     bool check = false;
        //     for(auto k : properties){
        //         if(first < k[0] && second < k[1]){
        //             check = true;
        //         }
        //     }
        //     if(check == true) {
        //         cnt++;
        //     }
        // }
        // return cnt;

        /* ---- 2 ------*/

        // sorting it  
        sort(properties.begin(), properties.end(), [](auto &a, auto &b){
            if (a[0] == b[0]) return a[1] < b[1]; 
            return a[0] > b[0]; 
        });

        // finding the weak characters
        int maxDefense = INT_MIN;
        int weakCount = 0;

        for (auto &p : properties) {
            if (p[1] < maxDefense) {
                weakCount++;
            }
            maxDefense = max(maxDefense, p[1]);
        }

        return weakCount;
    }
};