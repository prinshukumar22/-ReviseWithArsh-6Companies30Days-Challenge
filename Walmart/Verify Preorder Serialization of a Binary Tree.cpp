class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder[0] == '#' && preorder.size() > 1) return false; 

        int v = 1;
        stringstream ss(preorder);
        string str;
        while(getline(ss,str,',')){
            v--;
            if(v < 0) return false;
            if(str != "#") v+=2;
        }
        //cout<<v;
        return v==0;
    }
};
