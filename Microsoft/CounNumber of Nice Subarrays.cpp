class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int oddcnt = 0;
        int cnt = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%2) oddcnt++;
            if(oddcnt == k) cnt++;
            if(m[oddcnt - k]) cnt = cnt + m[oddcnt - k];
            m[oddcnt]++;
        }

        return cnt;
    }
};
