#define mod 1000000007
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &el: nums){
            pq.push(el);
        }

        while(k){
            int a = pq.top() + 1;
            pq.pop();
            pq.push(a);
            k--;
        }

        long long ans = 1;
        while(!pq.empty()){
            ans = (ans * (long long)pq.top())%mod;
            pq.pop();
        }

        return ans%mod;
    }
};
