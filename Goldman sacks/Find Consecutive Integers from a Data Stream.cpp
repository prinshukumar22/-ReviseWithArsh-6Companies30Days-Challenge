class DataStream {
public:
    int val,k;
    int cnt = 0;
    int timeout = 0;
    
    bool isVal = true;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        cnt++;
        if(num != val){
            timeout = cnt;
            isVal = false;
        }
        if(cnt < k){
            return false;
        }
        
        if(timeout + k <= cnt){
            isVal = true;
        }

        return isVal;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
