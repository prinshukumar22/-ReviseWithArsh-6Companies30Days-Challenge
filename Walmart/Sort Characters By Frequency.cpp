class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto &el :s){
            m[el]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto &el: m){
            pq.push({el.second,  el.first});
        }

        int j = 0;
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            for(int i=0;i<el.first;i++){
                s[j] = el.second;
                j++;
            }
        }

        return s;
    }
};
