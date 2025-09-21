class MovieRentingSystem {
public:
    // price[shop][movie] = price
    unordered_map<int, unordered_map<int,int>> price;

    // available[movie] = sorted set of (price, shop)
    unordered_map<int, set<pair<int,int>>> available;

    // rented = sorted set of (price, shop, movie)
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price[shop][movie] = p;
            available[movie].insert({p, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto &s = available[movie];
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < 5; ++it, ++cnt)
            ans.push_back(it->second);
        return ans;
    }

    void rent(int shop, int movie) {
        int p = price[shop][movie];
        available[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie) {
        int p = price[shop][movie];
        rented.erase({p, shop, movie});
        available[movie].insert({p, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            auto [p, shop, movie] = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};
