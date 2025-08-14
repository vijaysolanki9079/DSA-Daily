class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> extraSupplies;

        for (int k = 0; k < supplies.size(); ++k) {
            extraSupplies.insert(supplies[k]);
        }

        for (int i = 0; i < recipes.size(); ++i) {
            int cntIngredients = 0;

            for (int j = 0; j < ingredients[i].size(); ++j) {
                if (extraSupplies.find(ingredients[i][j]) !=
                    extraSupplies.end()) {
                    cntIngredients++;
                } else {
                    break;
                }
            }

            if (cntIngredients == ingredients[i].size()) {
                extraSupplies.insert(recipes[i]);
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};