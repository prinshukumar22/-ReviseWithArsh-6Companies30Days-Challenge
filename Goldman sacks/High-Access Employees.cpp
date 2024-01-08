class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        vector<string> ans;
        
        //sort the at
        sort(at.begin(), at.end());
        //string s = at[0][0];
        int j;
        int n = at.size();

        for(int i=0;i<n;){
            j = i+2;
            if(j<n && at[j][0] == at[i][0]){
                int a = stoi(at[i][1]);
                int b = stoi(at[j][1]);
                int m = ans.size();
                if(b-a < 100 && m == 0){
                    ans.push_back(at[i][0]);
                }
                else if(b-a < 100 && m != 0 && ans[m-1] != at[i][0]){
                    ans.push_back(at[i][0]);  
                }
                
            }
            i++;
        }

        return ans;
    }
};
