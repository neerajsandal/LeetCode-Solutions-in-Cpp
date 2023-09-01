//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void helper(int ind, string s, set<string> &ans)
	    {
	        if(ind == s.size()){
	            ans.insert(s);
	            return;
	        }
	        
	        for(int i = ind; i < s.size(); i++)
	        {
	            swap(s[ind], s[i]);
	            helper(ind+1, s, ans);
	            swap(s[ind], s[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    set<string> ans;
		    helper(0, S, ans);
		    vector<string> res;
		    for(auto it : ans)
		    {
		        res.push_back(it);
		    }
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends