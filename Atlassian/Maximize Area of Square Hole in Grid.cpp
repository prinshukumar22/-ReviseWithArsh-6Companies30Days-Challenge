class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int maxLen = 0;
        int i=0,j=1;
        while(j<hBars.size()){
            if(hBars[j] == hBars[j-1] + 1){
                j++;
            }else{
                maxLen = max(maxLen, j-i+1);
                i=j;
                j++;
            }
        }
        maxLen = max(maxLen, j-i+1);

        int maxWid = 0;
        i=0;
        j=1;
        while(j<vBars.size()){
            if(vBars[j] == vBars[j-1] + 1){
                j++;
            }else{
                maxWid = max(maxWid, j-i+1);
                i=j;
                j++;
            }
        }

        maxWid = max(maxWid, j-i+1);
        //cout<<maxWid<<endl;
        //cout<<maxLen<<endl;

        return min(maxLen,maxWid)*min(maxLen, maxWid);
    }
};
