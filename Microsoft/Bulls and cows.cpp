class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int sec[10] = {0};
        int gss[10] = {0};

        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]) bulls++;
            else{
                int sn = secret[i] - '0';
                int gn = guess[i] - '0';
                sec[sn]++;
                gss[gn]++;
            }
        }

        for(int i=0;i<10;i++){
            cows += min(sec[i], gss[i]);
        }

        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
