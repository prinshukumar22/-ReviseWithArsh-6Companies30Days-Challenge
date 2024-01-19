class Solution {
public:
    int findVal(pair<int,int> &p1, pair<int,int> &p2, pair<int,int> p3){
        int x1 = p1.first;
        int x2 = p2.first;
        int x3 = p3.first;

        int y1 = p1.second;
        int y2 = p2.second;
        int y3 = p3.second;

        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin() , trees.end());
        deque<pair<int,int>> upper,lower;

        for(auto &el: trees){
            int l = lower.size();
            int u = upper.size();

            while(l >= 2 && findVal(lower[l-2], lower[l-1], {el[0] , el[1]}) < 0){
                l--;
                lower.pop_back();
            }

            while(u >= 2 && findVal(upper[u-2], upper[u-1], {el[0] , el[1]}) > 0){
                u--;
                upper.pop_back();
            }

            upper.push_back({el[0] , el[1]});
            lower.push_back({el[0] , el[1]});
        }

        set<vector<int>> s;
        while(upper.size() > 0){
            s.insert({upper[0].first , upper[0].second});
            upper.pop_front();
        }

        while(lower.size() > 0){
            s.insert({lower[0].first , lower[0].second});
            lower.pop_front();
        }

        vector<vector<int>> res(s.begin() , s.end());

        return res;
    }
};
