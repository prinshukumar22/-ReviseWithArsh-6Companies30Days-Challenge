class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> cl = img;
        int a[] = {-1,0,1};
        int b[] = {-1,0,1};

        int n = img.size();
        int m = img[0].size();

        int i_;
        int j_;
        int sum = 0;
        int cnt = 0;
        int avg;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<=2;k++){
                    for(int h=0;h<=2;h++){
                        i_= i+a[k];
                        j_= j+b[h];
                        if(i_>=0 && i_<n && j_>=0 && j_<m){
                            sum += img[i_][j_];
                            cnt++;
                        }
                    }
                }
                avg = sum/cnt;
                cl[i][j] = avg;
                sum = 0;
                cnt = 0;
            }
        }

        return cl;
    }
};
