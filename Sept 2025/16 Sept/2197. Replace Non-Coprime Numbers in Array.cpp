#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long for intermediate LCM
        for (int x : nums) {
            long long val = x;
            while (!st.empty()) {
                long long g = gcd(st.back(), val);
                if (g == 1) break; // coprime, stop merging
                val = (st.back() / g) * val; // LCM
                st.pop_back();
            }
            st.push_back(val);
        }
        // convert back to int (problem guarantees ≤1e8)
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
