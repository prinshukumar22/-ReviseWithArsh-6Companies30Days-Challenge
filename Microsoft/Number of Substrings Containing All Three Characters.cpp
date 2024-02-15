class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int right = 0;
        int left = 0;
        int cnt = 0;

        vector<int> m(3,0);
        for(int i=0;i<n;i++){
            m[s[right] - 'a']++;
            while(m[0] > 0 && m[1] > 0 && m[2] > 0){
                cnt += n - right;
                m[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return cnt;
    }
};
