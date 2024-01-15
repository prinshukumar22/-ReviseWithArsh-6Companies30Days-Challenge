class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin() , nums.end(), 0);
        int inisum = 0;
        for(int i=0;i<n;i++){
            inisum += (i*nums[i]);
        }

        int maxi = inisum;

        for(int i=n-1;i>=0;i--){
            int sum = inisum + total_sum - (n*nums[i]);
            maxi = max(sum, maxi);

            inisum = sum;
        }

        return maxi;
    }
};
