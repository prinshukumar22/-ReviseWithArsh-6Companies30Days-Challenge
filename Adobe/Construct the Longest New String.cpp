class Solution {
public:
    int longestString(int x, int y, int z) {
        int cnt = 0;
        while(x > 0 && y > 0){
            cnt += 2;
            cnt += 2;

            x--;
            y--;
        }

        if(x>0) cnt +=2;
        if(y>0) cnt +=2;

        cnt += z*2;
        return cnt;
    }
};
