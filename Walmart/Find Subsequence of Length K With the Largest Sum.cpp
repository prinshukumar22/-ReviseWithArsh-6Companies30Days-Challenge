class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int , int>>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(k){
                pq.push({nums[i] , i});
                k--;
            }else{
                if(pq.top().first < nums[i]){
                    pq.pop();
                    pq.push({nums[i] , i});
                }
            }
        }

        vector<pair<int,int>> v;
        while(!pq.empty()){
            v.push_back({pq.top().second , pq.top().first});
            pq.pop();
        }

        sort(v.begin() , v.end());

        vector<int> ans;
        for(auto &el: v){
            ans.push_back(el.second);
        }

        return ans;
    }
};
