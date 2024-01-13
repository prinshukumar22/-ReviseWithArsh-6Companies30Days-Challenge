class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector<int> cl = nums;
        int j = n-1;
        int i = 1;
        for(i = 1;i<n;i+=2){
            cl[i] = nums[j];
            j--;
        }

        i = 0;
        for(i=0;i<n;i+=2){
            cl[i] = nums[j];
            j--;
        }

        nums = cl;
    }
};
