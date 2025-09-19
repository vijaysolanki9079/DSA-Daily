#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid; // rows x 26
    
    pair<int,int> parseCell(const string &cell) {
        // cell like "A1", "B10"
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }
    
    int getOperandValue(const string &op) {
        if (isalpha(op[0])) {
            // cell reference
            auto [r,c] = parseCell(op);
            if (r >= 0 && r < (int)grid.size() && c >= 0 && c < 26)
                return grid[r][c];
            else
                return 0;
        } else {
            // integer literal
            return stoi(op);
        }
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r,c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r,c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        // formula like "=A1+B2" or "=5+7"
        string s = formula.substr(1); // remove '='
        size_t plusPos = s.find('+');
        string op1 = s.substr(0, plusPos);
        string op2 = s.substr(plusPos + 1);
        
        int val1 = getOperandValue(op1);
        int val2 = getOperandValue(op2);
        return val1 + val2;
    }
};

