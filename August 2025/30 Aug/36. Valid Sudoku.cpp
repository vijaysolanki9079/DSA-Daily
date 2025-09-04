#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];
                if (num == '.') continue;

                // Check row
                if (rows[r].count(num)) return false;
                rows[r].insert(num);

                // Check column
                if (cols[c].count(num)) return false;
                cols[c].insert(num);

                // Check 3x3 box
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (boxes[boxIndex].count(num)) return false;
                boxes[boxIndex].insert(num);
            }
        }

        return true;
    }
};
