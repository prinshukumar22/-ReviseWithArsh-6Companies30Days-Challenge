class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin() , ast.end());

        long long masss = mass;

        for(int i=0;i<ast.size();i++){
            if(masss < ast[i]) return false;
            masss = masss + ast[i];
        }

        return true;
    }
};
