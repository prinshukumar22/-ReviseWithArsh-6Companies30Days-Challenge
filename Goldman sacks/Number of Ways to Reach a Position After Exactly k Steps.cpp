#define mod 1000000007
class Solution {
public:
    int solve(int s, int &e, int k, unordered_map<int, unordered_map<int,int>> &dp){
        if(s == e && k == 0) return 1;
        if(k < 0) return 0;

        if(dp[s].find(k) != dp[s].end()) return dp[s][k]%mod;

        int a = solve(s+1, e, k-1, dp)%mod;
        int b = solve(s-1, e, k-1, dp)%mod;

        return dp[s][k] = (a%mod + b%mod)%mod;
    }
    int numberOfWays(int s, int e, int k) {
        unordered_map<int, unordered_map<int,int>> dp;
        return solve(s, e, k, dp)%mod;
    }
};
