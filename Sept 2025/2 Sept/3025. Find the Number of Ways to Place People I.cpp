struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n): n(n), bit(n+1, INT_MIN) {}
    void update(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
    int query(int idx) {
        int res = INT_MIN;
        for (++idx; idx > 0; idx -= idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }
};

class Solution {
public:
    /* ------- 1 ------- */
    // int numberOfPairs(vector<vector<int>>& points) {
    //     int n = points.size();
    //     int ans = 0;

    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (i == j) continue;

    //             int x1 = points[i][0], y1 = points[i][1];
    //             int x2 = points[j][0], y2 = points[j][1];

    //             if (x1 <= x2 && y1 >= y2) {
    //                 bool valid = true;

    //                 for (int k = 0; k < n; k++) {
    //                     if (k == i || k == j) continue;

    //                     int x = points[k][0], y = points[k][1];
    //                     if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
    //                         valid = false;
    //                         break;
    //                     }
    //                 }

    //                 if (valid) ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    /* --------- 2 -------------*/
    // int numberOfPairs(vector<vector<int>>& points) {
    //     sort(points.begin(), points.end(), [](auto &a, auto &b) {
    //         if (a[0] != b[0]) return a[0] < b[0];
    //         return a[1] > b[1];
    //     });

    //     int n = points.size();
    //     int ans = 0;

    //     for (int i = 0; i < n; i++) {
    //         int maxY = INT_MIN;
    //         for (int j = i + 1; j < n; j++) {
    //             if (points[i][1] >= points[j][1] && points[j][1] > maxY) {
    //                 ans++;
    //                 maxY = points[j][1];
    //             }
    //         }
    //     }
    //     return ans;
    // }

    /* -------- 3 -------- */ 
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int n = points.size();
        int ans = 0;
        int maxY = 51; // since y ≤ 50
        Fenwick bit(maxY);

        for (int i = 0; i < n; i++) {
            int maxSeen = INT_MIN;
            for (int j = i+1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    if (points[j][1] > maxSeen) {
                        ans++;
                        maxSeen = points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};
