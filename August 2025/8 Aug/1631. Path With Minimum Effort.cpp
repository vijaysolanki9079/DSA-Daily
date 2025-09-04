class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top(); pq.pop();

            if (r == m - 1 && c == n - 1) return effort;

            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nextEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));
                    if (nextEffort < dist[nr][nc]) {
                        dist[nr][nc] = nextEffort;
                        pq.push({nextEffort, nr, nc});
                    }
                }
            }
        }

        return 0; 
    }
};