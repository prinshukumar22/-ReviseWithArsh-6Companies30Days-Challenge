class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 0);
        vector<int> hash(n);
        int maxi = 0;
        int st = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (maxi < dp[i]) {
                maxi = dp[i];
                st = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[st]);
        while (hash[st] != st) {
            st = hash[st];
            ans.push_back(nums[st]);
        }

        return ans;
    }
};
