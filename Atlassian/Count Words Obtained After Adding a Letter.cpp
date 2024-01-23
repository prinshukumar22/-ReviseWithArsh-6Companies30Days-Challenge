class Solution {
public:
    int wordCount(vector<string>& sw, vector<string>& tw) {
        unordered_set<string> st;
        for(auto &el:sw){
            sort(el.begin() , el.end());
            st.insert(el);
        }

        int cnt = 0;
        for(auto &el: tw){
            sort(el.begin() , el.end());
            for(int i=0;i<el.size();i++){
                string x = el.substr(0,i) + el.substr(i+1);
                if(st.count(x)){
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};
