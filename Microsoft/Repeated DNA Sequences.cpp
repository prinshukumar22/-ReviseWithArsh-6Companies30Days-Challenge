class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> ans;
        int n = s.size();

        if(n <= 10) return ans;
        //cout<<n<<endl;
        for(int i=0;i<=n-10;i++){
            //cout<<s.substr(i,10)<<endl;
            m[s.substr(i,10)]++;
        }

        for(auto &el:m){
            if(el.second > 1) ans.push_back(el.first);
        }

        return ans;
    }
};
