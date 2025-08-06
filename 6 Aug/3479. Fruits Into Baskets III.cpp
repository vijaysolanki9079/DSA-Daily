class Solution {
public:
    /* ----- TLE ---- */
    // int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    //      int n = fruits.size();
    //     int m = baskets.size();
    //     vector<bool> used(m, false); 
    //     int unplaced = 0;

    //     for (int i = 0; i < n; ++i) {
    //         bool placed = false;
    //         for (int j = 0; j < m; ++j) {
    //             if (!used[j] && baskets[j] >= fruits[i]) {
    //                 used[j] = true;
    //                 placed = true;
    //                 break;
    //             }
    //         }
    //         if (!placed) unplaced++;
    //     }

    //     return unplaced;
    // }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = static_cast<int>(sqrt(n));
        int section = (n + m - 1) / m;
        int count = 0;
        vector<int> maxV(section, 0);
        
        for (int i = 0; i < n; i++) {
            maxV[i / m] = max(maxV[i / m], baskets[i]);
        }
        
        // Process each fruit
        for (int fruit : fruits) {
            int unset = 1;
            // Check each section
            for (int sec = 0; sec < section; sec++) {
                if (maxV[sec] < fruit) {
                    continue;
                }
                int choose = 0;
                maxV[sec] = 0;
                // Process elements in current section
                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && !choose) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n) {
                        maxV[sec] = max(maxV[sec], baskets[pos]);
                    }
                }
                unset = 0;
                break;
            }
            count += unset;
        }
        return count;
    }
};