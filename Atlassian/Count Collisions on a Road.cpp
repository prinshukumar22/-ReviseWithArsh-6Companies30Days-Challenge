class Solution {
public:
    int countCollisions(string dir) {
        int i = 0;
        int col = 0;
        while(i < dir.size() - 1){
            if(dir[i] == 'R' && dir[i+1] == 'L'){
                col = col + 2;
                dir[i] = 'S';
                dir[i+1] = 'S';
                if(i != 0) i--;
            }
            else if((dir[i] == 'R' && dir[i+1] == 'S') || (dir[i] == 'S' && dir[i+1] == 'L')){
                col = col + 1;
                dir[i] = 'S';
                dir[i+1] = 'S';
                if(i != 0) i--;
            }else{
                i++;
            }
        }

        return col;
    }
};
