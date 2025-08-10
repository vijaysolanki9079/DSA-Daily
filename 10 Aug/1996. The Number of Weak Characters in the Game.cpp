class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        int cnt = 0;

        for(auto it : properties){
            int first = it[0];
            int second = it[1];

            bool check = false;
            for(auto k : properties){
                if(first < k[0] && second < k[1]){
                    check = true;
                }
            }
            if(check == true) {
                cnt++;
            }
        }
        return cnt;
    }
};