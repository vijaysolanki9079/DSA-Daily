class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    bool valid(int x, int y, vector<vector<int>>& g) {
        return (x >= 0 && y >= 0 && x < g.size() && y < g[0].size());
    }

    bool checkSeq(int val, int step) {
        if (step == 0) return val == 1;      
        if (step % 2 == 1) return val == 2;  
        return val == 0;                    
    }

    int solve2(int x, int y, vector<vector<int>>& g, int d, int step) {
        int len = 0;
        while (valid(x, y, g) && checkSeq(g[x][y], step)) {
            len++;
            x += dir[d].first;
            y += dir[d].second;
            step++;
        }
        return len;
    }

    int solve(int x, int y, vector<vector<int>>& g, int d) {
        int step = 0;
        int len = 0;
        int ans = 0;

        int nx = x, ny = y;
        while (valid(nx, ny, g) && checkSeq(g[nx][ny], step)) {
            len++;
            ans = max(ans, len);

           
            int nd = (d + 1) % 4;
            int shift1 = solve2(nx + dir[nd].first, ny + dir[nd].second, g, nd, step + 1);
            ans = max(ans, len + shift1);

           
            nx += dir[d].first;
            ny += dir[d].second;
            step++;
        }
        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, solve(i, j, g, d));
                    }
                }
            }
        }
        return ans;
    }
};