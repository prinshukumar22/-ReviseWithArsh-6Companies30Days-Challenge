//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans = "";
  int n = src.size();
  
  for(int i=0;i<n;){
    char ch = src[i];
    int j = i;
    while(src[j] == ch){
        j++;
    }
    ans.push_back(ch);
    ans = ans + to_string(j-i);
    i = j;
  }
  
  return ans;
}     
 
