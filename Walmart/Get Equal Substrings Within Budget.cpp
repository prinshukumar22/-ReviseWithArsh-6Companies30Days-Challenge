class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int len = 0;

        int i=0;

        for(int j=0;j<n;j++){
            maxCost -= (abs(s[j] - t[j]));

            while(maxCost < 0){
                len = max(len, j-i);
                maxCost += (abs(s[i] - t[i]));
                i++;
            }
        }

        if(maxCost >= 0){
            len = max(len , n-i);
        }

        return len;
    }
};
