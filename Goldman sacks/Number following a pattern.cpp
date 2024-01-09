//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here
        string ans = "";
        
        stack<int> s;
        
        for(int i=0;i<S.size();i++){
            if(S[i] == 'D'){
                s.push(i+1);
            }else{
                ans = ans + to_string(i+1);
                while(!s.empty()){
                    ans = ans + to_string(s.top());
                    s.pop();
                }
            }
        }
        
        ans = ans + to_string(S.size() + 1);
        while(!s.empty()){
                ans = ans + to_string(s.top());
                s.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
