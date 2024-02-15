class Solution {
public:
    vector<int> prefix(string pat , int n){
            vector<int> pi(n,0);
            int pre =0;
            int suf=1;
            while(suf<n){
                if(pat[pre]==pat[suf]){
                    pi[suf]=pre+1;
                    pre++;
                    suf++;
                }
                else{
                    if(pre==0){
                        pi[suf]=0;
                        suf++;
                    }
                    else{
                        pre = pi[pre-1];
                    }
                }
            }
            
            return pi;
        }

    string longestPrefix(string s) {
        auto a = prefix(s,s.size());
        
        return s.substr(0,a.back());
    }
};
