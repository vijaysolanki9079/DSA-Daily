class Solution {
public:
    /*--------- 1 ---------- */
    int count1s = 0;
    int count2s = 0;
    int count3s = 0;

    void findThreeSideMatrix(int i, int j, vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i+2 >= n || j+2 >= m) return; 

        for(int x = i; x < i+3; x++) {
            for(int y = j; y < j+3; y++) {
                if(matrix[x][y] != 1) return;
            }
        }
        count3s++;
    }

    void findTwoSideMatrix(int i, int j, vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i+1 >= n || j+1 >= m) return; 

        if(matrix[i][j] == 1 && matrix[i][j+1] == 1 &&
           matrix[i+1][j] == 1 && matrix[i+1][j+1] == 1) {
            count2s++;
            findThreeSideMatrix(i, j, matrix); 
        }
    } 

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        count1s = count2s = count3s = 0;

        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(matrix[i][j] == 1) {
                    count1s++;
                    findTwoSideMatrix(i, j, matrix);
                }
            }
        }
        
        return count1s + count2s + count3s; 
    }
};