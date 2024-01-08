class Solution {
public:
    int n;
    int m;
    int i = 0, j = 0;
    Solution(int n, int m) {
        this->n = n;
        this->m = m;
    }

    vector<int> flip() {
        int I = i, J = j;
        if(j+1 < m){
            j++;
        }else if(i+1 < n){
            i++;
            j = 0;
        }else{
            i = 0;
            j = 0;
        }

        return {I,J};
    }
    
    void reset() {
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
