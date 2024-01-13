class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int m = nums.size();

        string s;
        int n = nums[0].size();

        vector<int> ans;

        for(auto &el: queries){
            int smallest = el[0];
            int digits = el[1];
            priority_queue<pair<string,int>> pq;

            for(int i=0;i<m;i++){
                s = nums[i].substr(n-digits);
                if(smallest){
                    pq.push({s, i});
                    smallest--;
                }else{
                    if(pq.top().first > s){
                        pq.pop();
                        pq.push({s, i});
                    }
                }
            }

            ans.push_back(pq.top().second);
            //pq.erase();
        }

        return ans;
    }
};
