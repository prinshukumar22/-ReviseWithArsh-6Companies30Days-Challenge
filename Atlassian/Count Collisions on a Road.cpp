class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        int i=0;
        int j=n-1;

        while(i<n && dir[i] == 'L') i++;
        while(j>=0 && dir[j] == 'R') j--;

        int cnt = 0;
        for(int k = i;k<=j;k++){
            if(dir[k] != 'S') cnt++;
        }

        return cnt;
    }
};
