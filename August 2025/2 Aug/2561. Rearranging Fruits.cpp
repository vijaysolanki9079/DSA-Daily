class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> freq;

        for(auto x : basket1) freq[x]++;
        for(auto x : basket2) freq[x]--;

        vector<int> toSwap;
        for(auto [val,count] : freq){
            if(count % 2 == 1) return -1;
            for(int i = 0;i<abs(count)/2;i++){
                toSwap.push_back(val);
            }
        }

        // Sort both excess 
        sort(toSwap.begin(), toSwap.end());

        int m = min(*min_element(basket1.begin(), basket1.end()),
                    *min_element(basket2.begin(), basket2.end()));

        long long res = 0;
        for (int i = 0; i < toSwap.size() / 2; ++i) {
            res += min(toSwap[i], 2 * m); 
        }
        return res;
    }
};

