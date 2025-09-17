#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, pair<string,int>> foodInfo;
    unordered_map<string, set<pair<int,string>>> cuisineMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0;i<foods.size();i++) {
            foodInfo[foods[i]]={cuisines[i],ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine,oldRating]=foodInfo[food];
        cuisineMap[cuisine].erase({-oldRating,food});
        foodInfo[food]={cuisine,newRating};
        cuisineMap[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */