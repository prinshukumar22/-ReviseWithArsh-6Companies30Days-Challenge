class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& re) {
        map<pair<int,int>, int> m;
        for(auto &el: re){
            m[{el[0],el[1]}]++;
            m[{el[2],el[3]}]++;
            m[{el[0],el[3]}]--;
            m[{el[2],el[1]}]--;
        }

        int cnt = 0;
        for(auto &el: m){
            if(el.second != 0){
                if(abs(el.second) != 1) return false;
                cnt++;
            }
        }

        return cnt == 4;
    }
};
