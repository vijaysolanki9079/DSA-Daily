class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [g, pr] = pq.top(); pq.pop();
            int p = pr.first, t = pr.second;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }
        double res = 0;
        while (!pq.empty()) {
            auto [g, pr] = pq.top(); pq.pop();
            res += (double)pr.first / pr.second;
        }
        return res / classes.size();
    }
};
