#define mod 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int> ans(n+1, 0);
        ans[1] = 1;
        for(int i=1;i<=n;i++){
            for(int j = i+d; j<i+f && j<=n;j++){
                ans[j] = (ans[j]%mod + ans[i]%mod)%mod;
            }
        }

        int cnt = 0;
        for(int i=n;i>n-f;i--){
            cnt = (cnt%mod + ans[i]%mod)%mod;
        }

        return cnt%mod;
    }
};
