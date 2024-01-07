class Solution {
public:
    bool issorted(vector<int>& nums, int s, int e, int &n){
        int prev = 0;
        for(int i=0;i<n;i++){
            if(i>=s && i<=e) continue;
            if(nums[i]>prev){
                prev = nums[i];
            }else{
                return false;
            }
        }

        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(issorted(nums,i,j, n)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
