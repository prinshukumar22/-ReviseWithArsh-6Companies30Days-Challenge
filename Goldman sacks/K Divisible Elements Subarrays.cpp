class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;

        int n = nums.size();
        vector<int> ans;
        int cnt;
        for(int i=0;i<n;i++){
            cnt = 0;
            ans.clear();
            for(int j=i;j<n;j++){
                ans.push_back(nums[j]);
                if(nums[j]%p == 0){
                    cnt++;
                }
                if(cnt <= k){
                    s.insert(ans);
                }else{
                    break;
                }
            }
        }

        return s.size();
    }
};
