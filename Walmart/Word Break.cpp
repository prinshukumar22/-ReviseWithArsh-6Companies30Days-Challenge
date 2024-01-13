class Solution {
public:
    bool solve(int inx, int &n, set<string> &v, string &str, vector<int> &dp){
        if(inx == n){
            return true;
        }
        if(dp[inx] != -1) return dp[inx];
        
        string s = "";
        for(int i=inx;i<n;i++){
            s = s + str[i];
            if(v.count(s)){
                bool ans = solve(i+1, n, v, str, dp);
                if(ans) return dp[inx] = true;
            }
        }
        
        return dp[inx] = false;
    }
    
    bool wordBreak(string str, vector<string>& wordDict) {
        set<string> v(wordDict.begin(), wordDict.end());
        int n = str.size();
        
        vector<int> dp(n+1, -1);
        
        return solve(0, n, v, str, dp);
    }
};