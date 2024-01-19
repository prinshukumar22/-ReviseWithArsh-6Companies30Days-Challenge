#include <algorithm>
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bd) {
        vector<vector<int>> co;
        vector<vector<int>> ans;
        for(auto &el: bd){
            int xl = el[0];
            int xr = el[1];
            int y = el[2];

            co.push_back({xl,-y});
            co.push_back({xr, y});
        }

        sort(co.begin() , co.end());
        multiset<int, greater<int>> s;
        s.insert(0);
        int prev = 0;

        for(auto &el: co){
            int x = el[0];
            int y = el[1];
            if(y < 0){
                s.insert(-y);
                //cout<<*s.begin()<<" "<<-y<<endl;
                if(prev != *(s.begin())){
                    ans.push_back({x,-y});
                    prev = -y;
                }
            }else {
                s.erase(s.find(y));
                if(prev != *s.begin()){
                    ans.push_back({x,*s.begin()});
                    prev = *s.begin();
                }
            }
        }

        return ans;
    }
};
