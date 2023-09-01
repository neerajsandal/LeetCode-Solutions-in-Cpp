//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void helper(vector<string> &str, string s, string s1,int ind)
	    {
	        if(ind == s.size())
	        {
	            if(s1 != "") str.push_back(s1);
	            return;
	        }
	        s1 += s[ind];
	        helper(str, s, s1, ind+1);
	        s1.pop_back();
	        
	        helper(str, s, s1, ind+1);
	    }
		vector<string> AllPossibleStrings(string s){
            vector<string> str;
            string s1 = "";
            helper(str, s, s1, 0);
            sort(str.begin(), str.end());
            return str;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends