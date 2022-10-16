//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int n = S.size();
	    int table[n];
	    int sum = 0, x = 0;
	    if(S[0] == '0'){
	        table[0] = 1;
	        sum = 1;
	    }
	    else {
	        table[0] = -1;
	        sum = -1;
	    }
	    
	    for(int i = 1; i < n; i++){
	        if(S[i] == '0'){
	            x = 1;
	        }else{
	            x = -1;
	        }
	        if(sum == -1){
	            sum = x;
	        }
	        else
	        sum += x;
	        table[i] = max(sum, table[i-1]);
	    }
	    return table[n-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends