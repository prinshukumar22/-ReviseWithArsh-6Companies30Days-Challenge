class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int inx = n/2;
        int el = nums[inx];
        
        int mini = 0;

        for(auto &el2:nums){
            mini += abs(el - el2);
        }

        return mini;
    }
};
