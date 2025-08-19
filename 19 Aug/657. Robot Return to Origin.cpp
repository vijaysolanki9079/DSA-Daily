class Solution {
public:
    // bool judgeCircle(string moves) {
    //     int n = moves.size();
    //     int x=0, y=0;
    //     for(int i=0 ; i<n ; ++i){
    //         char ch = moves[i];
    //         if(ch == 'U' ){
    //             y += 1;
    //         } else if(ch == 'D') {
    //             y += -1;
    //         } else if(ch == 'L'){
    //             x += -1;
    //         } else if(ch == 'R'){
    //             x += 1;
    //         }
    //     }

    //     if(x==0 && y == 0) return true;
    //     else return false;
    // }
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char ch : moves) {
            switch(ch) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
            }
        }
        return x == 0 && y == 0;
    }
};
