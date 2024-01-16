class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0;
        int mini = n;
        
        for(auto i: left){
            maxi = max(maxi , i);
        }
        
        for(auto i: right){
            mini = min(mini , i);
        }
        
        
        //int a1 = abs(n - maxi);
        int a2 = abs(n - mini);
        
        return max(maxi, a2);
    }
};