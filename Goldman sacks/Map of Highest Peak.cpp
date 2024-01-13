class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int n = w.size();
        int m = w[0].size();

        vector<vector<int>> ans(n, vector<int>(m,-1));

        //jaha water hai udar ki height 0karo or multisource bfs lagao
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(w[i][j]){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        //apply bfs
        vector<int> temp = {-1,0,1,0,-1};
        while(!q.empty()){
            auto pt = q.front();
            q.pop();

            int x = pt.first;
            int y = pt.second;
            int v = ans[x][y];

            for(int i=0;i<4;i++){
                int a = x+temp[i];
                int b = y+temp[i+1];

                if(a >=0 && a < n && b>=0 && b<m && ans[a][b] == -1){
                    ans[a][b] = v+1;
                    q.push({a,b});
                }
            }

        }

        return ans;
    }
};
