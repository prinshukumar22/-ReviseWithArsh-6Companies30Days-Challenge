class Solution {
public:
    int solve(int sub, vector<vector<int>> &dist, int &n){
        int mx = 0, nd = 0, ed =0;
        for(int i=0;i<n;i++){
            if(((sub>>i)&1)){
                nd++;
                for(int j=i+1;j<n;j++){
                    if(((sub>>j)&1)){
                        if(dist[i][j] == 1) ed++;
                        mx = max(mx, dist[i][j]);
                    }
                }
            }
        }

        if(ed == nd - 1){
            return mx;
        }
        return -1;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto &el: edges){
            dist[el[0] - 1][el[1] - 1] = 1;
            dist[el[1] - 1][el[0] - 1] = 1;
        }
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = dist[j][i] = min(dist[i][j], min(dist[j][i] , dist[i][k] + dist[k][j]));
                    } 
                }
            }
        }

        vector<int> v(n-1,0);
        for(int i=0;i<(1<<n);i++){
            int ans = solve(i, dist, n);
            if(ans > 0){
                v[ans-1]++;
            }
        }

        return v;
    }
};
