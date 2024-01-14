class Solution {
public:
    int solve(int inx, string &s, unordered_set<string> &dict, int &n, vector<int> &dp){
        if(inx >= n) return 0;

        if(dp[inx] != -1) return dp[inx];

        int mini = n;
        string str = "";
        for(int i=inx; i<n;i++){
            str.push_back(s[i]);
            int a = 0;
            if(!dict.count(str)){
                a = str.size();
            }
            int b = solve(i+1, s, dict, n, dp);

            mini = min(mini , a + b);
        }

        return dp[inx] = mini;
    }
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string> dict;

        for(auto &el: d){
            dict.insert(el);
        }

        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, dict, n, dp);
    }
};
