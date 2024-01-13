class Solution {
public:
    int res = 0;

    bool isPalin(string s){
        int i=0;
        int j = s.size()-1;

        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string &s, int inx, string &s1, string &s2, int &n){

        if(inx >= n){
            if(isPalin(s1) && isPalin(s2)){
                res = max(res, (int)s1.length()*(int)s2.length());
            }
            return;
        }

        s1.push_back(s[inx]);
        solve(s, inx+1, s1, s2, n);
        s1.pop_back();

        s2.push_back(s[inx]);
        solve(s, inx+1, s1, s2, n);
        s2.pop_back();

        solve(s, inx+1, s1, s2, n);
    }

    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";

        int n = s.size();
        solve(s, 0, s1, s2, n);

        return res;
    }
};
