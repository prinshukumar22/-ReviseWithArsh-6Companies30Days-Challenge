class Solution {
public:
    void solve(int& n, int& m, vector<int>& str1, vector<int>& str2, int& maxi) {
        // vector<vector<int>> dp(n+1, vector<int>(m+1 , 0));
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int maxi = 0;
        solve(n, m, nums1, nums2, maxi);

        return maxi;
    }
};
