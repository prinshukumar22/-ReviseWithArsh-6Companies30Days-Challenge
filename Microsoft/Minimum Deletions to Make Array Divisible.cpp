class Solution {
public:
    int getGcd(int i, vector<int>& nd){
        if(i == nd.size()-1){
            return nd[i];
        }

        return __gcd(nd[i] , getGcd(i+1, nd));
    }

    int minOperations(vector<int>& nums, vector<int>& nd) {
        //find gcd of nd
        int gcd = getGcd(0,nd);
        //cout<<gcd<<endl;
        sort(nums.begin() , nums.end());
        for(int i=0;i<nums.size();i++){
            if(gcd%nums[i] == 0){
                return i;
            }
        }

        return -1;
    }
};
