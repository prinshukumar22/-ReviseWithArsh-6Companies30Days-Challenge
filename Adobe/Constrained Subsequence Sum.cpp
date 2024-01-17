class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> t(nums.begin() , nums.end());
        
        priority_queue<pair<int,int>> pq;
        
        pq.push({t[0] , 0});
        int result = t[0];
        
        for(int i=1;i<nums.size();i++){
            while(!pq.empty() && i - pq.top().second > k){
                pq.pop();
            }
            
            t[i] = max(t[i] , nums[i] + pq.top().first);
            pq.push({t[i] , i});
            result = max(t[i] , result);
        }
        
        return result;
    }
};
