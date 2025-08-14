class State {
public:
    int x, y, steps, k;
    State(int _x, int _y, int _steps, int _k)
        : x(_x), y(_y), steps(_steps), k(_k) {}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(
            n, vector<int>(m, -1)); 

        queue<State> q;
        q.push(State{0, 0, 0, K});
        visited[0][0] = K;

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y, steps, k] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1)
                return steps;

            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int nk = k - grid[nx][ny]; 
                if (nk >= 0 && visited[nx][ny] < nk) {
                    visited[nx][ny] = nk;
                    q.push({nx, ny, steps + 1, nk});
                }
            }
        }
        return -1;
    }
};