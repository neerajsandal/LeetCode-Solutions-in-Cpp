//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int x, sum = 0;
	    int count = 0;
	    int table[S.size()] = {0};
	    if(S[0] == '1'){
	        table[0] = -1;
	        sum = -1;
	    }
	    else{
	        table[0] = 1;
	        sum = 1;
	        count++;
	    }
	    for(int i = 1; i < S.size(); i++){
	        if(S[i] == '0'){
	            x = 1;
	            count++;
	        }
	        else if(S[i] == '1'){
	            x = -1;
	        }
	        if(sum <= 0)
	        sum = x;
	        else
	        sum += x;
	        
	        table[i] = max(sum, table[i-1]);
	    }
	    if(count == 0){
	        return -1;
	    }
	    return table[S.size()-1];
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