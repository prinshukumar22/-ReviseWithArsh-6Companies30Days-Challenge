class Solution {
public:
    static bool comp(string &a, string &b){
        if(a.size() == b.size()){
            return a < b;
        }
        return a.size() > b.size();
    }

    bool isSub(string &s, string el){
        int i=0;
        int j = 0;
        if(el.size() > s.size()) return false;

        while(i<s.size() && j<el.size()){
            if(s[i] == el[j]) j++;
            i++;
        }

        return j == el.size();
    }

    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin() , dict.end(), comp);

        for(auto &el:dict){
            if(isSub(s, el)) return el;
        }

        return "";
    }
};
