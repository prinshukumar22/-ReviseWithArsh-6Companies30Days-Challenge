class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int> win;
        map<int,int> lose;

        for(auto &el: mat){
            win[el[0]]++;
            lose[el[1]]++;
        }

        vector<int> w;
        vector<int> l;

        for(auto &el: win){
            int pl = el.first;
            if(!lose[pl]) w.push_back(pl);
        }

        for(auto &el:lose){
            if(el.second == 1) l.push_back(el.first);
        }

        return {w,l};
    }
};