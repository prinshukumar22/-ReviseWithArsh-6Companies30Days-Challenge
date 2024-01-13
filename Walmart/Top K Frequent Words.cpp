class Solution {
public:
    static bool comp(pair<int,string> &a, pair<int,string> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }

        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        
        for(auto &el: words){
            m[el]++;
        }

        vector<pair<int,string>> v;

        for(auto &el : m){
            v.push_back({el.second , el.first});
        }

        sort(v.begin() , v.end(), comp);
        
        vector<string> ans;
        int i=0;
        while(k--){
            ans.push_back(v[i].second);
            i++;
        }
        
        return ans;
    }
};
