class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& ori, vector<char>& cha, vector<int>& c) {
        //floyd warshall lagao
        //step 1 adjacency matrix banao
        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX));
        int n = s.size();
        int m = cha.size();

        for(int i=0;i<m;i++){
            adj[ori[i] - 'a'][cha[i] - 'a'] = min(adj[ori[i] - 'a'][cha[i] - 'a'], (long long)c[i]);
        }

        //floyd warshall algo;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        long long res = 0;
        for(int i=0;i<n;i++){
            if(s[i] == t[i]) continue;
            long long cost = adj[s[i] - 'a'][t[i] - 'a'];
            if(cost == INT_MAX) return -1;
            res += cost;
        }

        return res;
    }
};
