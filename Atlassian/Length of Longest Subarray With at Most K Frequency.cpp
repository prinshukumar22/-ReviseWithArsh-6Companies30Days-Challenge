class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0,res = 0;
        unordered_map<int,int> m;

        while(j<n){
            int el = nums[j];
            if(m[el] + 1 <= k){
                m[el]++;
                j++;
            }
            else{
                res = max(res, j-i);
                m[nums[i]]--;
                i++;
            }
        }
        res = max(res, j-i);
        return res;
    }
};
