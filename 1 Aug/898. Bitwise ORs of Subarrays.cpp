class Solution {
public:
    /* ------- 1 (TLE)------ */
    // for (int i = 0; i < n; ++i) {
    //     int orVal = 0;
    //     for (int j = i; j < n; ++j) {
    //         orVal |= arr[j];
    //         result.insert(orVal);
    //     }
    // }

    /* ------- 2 ------*/
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;      // all unique OR values
        unordered_set<int> current;     // ORs ending at current position
        unordered_set<int> next;

        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int val : current) {
                next.insert(val | num);
            }
            current = next;
            for (int val : current) {
                result.insert(val);
            }
        }
        return result.size();
    }
};