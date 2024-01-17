class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        set<int> left({2,3,4,5});
        set<int> mid({4,5,6,7});
        set<int> right({6,7,8,9});

        int m = rs.size();
        sort(rs.begin() , rs.end());
        int cnt = 0;
        int cnt2 = 0;
        int i=0;
        while(i<m){
            int rown = rs[i][0];
            int j = i;
            cnt2++;
            bool l = true;
            bool mi = true;
            bool r = true;
            while(j<m && (rown == rs[j][0])){
                if(left.count(rs[j][1])) l = false;
                if(mid.count(rs[j][1])) mi = false;
                if(right.count(rs[j][1])) r = false;
                j++;
            }
            if(l && r) cnt += 2;
            else if(mi || l || r) cnt += 1;
            i = j;
        }

        int rem = n - cnt2;
        cnt += rem*2;

        return cnt;
    }
};
