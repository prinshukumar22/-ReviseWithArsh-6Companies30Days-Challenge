class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        int maxi = 0;
        int n = pts.size();
        if(n == 1) return 1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dy = pts[j][1] - pts[i][1];
                int dx = pts[j][0] - pts[i][0];
                int cnt = 2;

                for(int k=0;k<n;k++){
                    if(k == i || k == j) continue;
                    int dx_ = pts[k][0] - pts[i][0];
                    int dy_ = pts[k][1] - pts[i][1];
                    if(dx*dy_ == dx_*dy){
                        cnt++;
                    }
                }
                maxi = max(maxi,cnt);
            }
        }

        return maxi;
    }
};
