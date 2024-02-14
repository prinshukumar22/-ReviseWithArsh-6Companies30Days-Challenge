class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> ltr;
        stack<int> rtl;
        int n = nums.size();
        int l = nums.size();
        int r = 0;
        for(int i=0;i<n;i++){
            while(!ltr.empty() && nums[ltr.top()] > nums[i]){
                l = min(ltr.top() , l);
                ltr.pop();
            }
            ltr.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!rtl.empty() && nums[rtl.top()] < nums[i]){
                r = max(rtl.top() , r);
                rtl.pop();
            }
            rtl.push(i);
        }
        //cout<<l<<" "<<r;
        return r-l+1 <= 0 ? 0 : r-l+1;
    }
};
