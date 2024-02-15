class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        if(!helper(p1,p2,s)||
        !helper(p1,p3,s)||
        !helper(p1,p4,s)||
        !helper(p2,p3,s)||
        !helper(p2,p4,s)||
        !helper(p3,p4,s)) return false;

        return s.size() == 2 ? true : false;
    }

    bool helper(vector<int> &s, vector<int> &e, set<int> &st){
        if((s[0] == e[0]) && (s[1] == e[1])) return false;
        int dist = (s[0] - e[0])*(s[0] - e[0]) + (s[1] - e[1])*(s[1] - e[1]);
        st.insert(dist);
        return true;
    }
};
