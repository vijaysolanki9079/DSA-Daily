class Solution {
public:
    /* ------- 1 (TLE)--------*/       
    // vector<string> findAllRecipes(vector<string>& recipes,
    //                               vector<vector<string>>& ingredients,
    //                               vector<string>& supplies) {
    //     vector<string> ans;
    //     unordered_set<string> extraSupplies;

    //     for (int k = 0; k < supplies.size(); ++k) {
    //         extraSupplies.insert(supplies[k]);
    //     }

    //     for (int i = 0; i < recipes.size(); ++i) {
    //         int cntIngredients = 0;

    //         for (int j = 0; j < ingredients[i].size(); ++j) {
    //             if (extraSupplies.find(ingredients[i][j]) !=
    //                 extraSupplies.end()) {
    //                 cntIngredients++;
    //             } else {
    //                 break;
    //             }
    //         }

    //         if (cntIngredients == ingredients[i].size()) {
    //             extraSupplies.insert(recipes[i]);
    //             ans.push_back(recipes[i]);
    //         }
    //     }
    //     return ans;
    // }

    /* ------ 2 ------------*/
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        queue<string> q;
        vector<string> ans;

        for (int i = 0; i < recipes.size(); ++i) {
            indegree[recipes[i]] = (int)ingredients[i].size();
            for (const string &ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        for (const string &s : supplies) q.push(s);

        for (const string &r : recipes) {
            if (indegree[r] == 0) {
                ans.push_back(r);
                q.push(r);
            }
        }

        while (!q.empty()) {
            string item = q.front(); q.pop();
            for (const string &rec : graph[item]) {
                indegree[rec]--;
                if (indegree[rec] == 0) {
                    ans.push_back(rec);
                    q.push(rec);
                }
            }
        }

        return ans;
    }
};
