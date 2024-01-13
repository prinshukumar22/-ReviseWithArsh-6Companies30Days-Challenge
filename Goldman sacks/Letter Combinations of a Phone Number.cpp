class Solution {
public:
    void solve(int inx, int &n, string &digits, unordered_map<char, string> &m, vector<string> &ans, string &s){
        if(inx == n){
            ans.push_back(s);
            return;
        }
        
        for(auto &el: m[digits[inx]]){
            s.push_back(el);
            solve(inx+1, n, digits, m, ans, s);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        int n = digits.size();
        if(n==0) return ans;
        string s = "";
        solve(0, n, digits, m, ans, s);
        
        return ans;
    }
};
