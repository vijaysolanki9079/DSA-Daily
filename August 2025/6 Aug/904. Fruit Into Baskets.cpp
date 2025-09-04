class Solution {
public:
    // int totalFruit(vector<int>& fruits) {
        // int left = 0, maxLen = 0;
        // unordered_map<int, int> count;

        // for (int right = 0; right < fruits.size(); ++right) {
        //     count[fruits[right]]++;

        //     while (count.size() > 2) {
        //         count[fruits[left]]--;
        //         if (count[fruits[left]] == 0)
        //             count.erase(fruits[left]);
        //         left++;
        //     }

        //     maxLen = max(maxLen, right - left + 1);
        // }

        // return maxLen;
    // }

    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCount = 0, currMax = 0, maxFruits = 0;

        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                currMax++;
            } else {
                currMax = lastFruitCount + 1;
            }

            if (fruit == lastFruit) {
                lastFruitCount++;
            } else {
                secondLastFruit = lastFruit;
                lastFruit = fruit;
                lastFruitCount = 1;
            }

            maxFruits = max(maxFruits, currMax);
        }

        return maxFruits;
    }
};
