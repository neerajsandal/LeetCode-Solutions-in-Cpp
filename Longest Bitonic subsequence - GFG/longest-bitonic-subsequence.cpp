//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    int n = arr.size();
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
	    int maxi = 0;
	    
	    // longest Increasing Subsequence
	    for(int i = 0; i < n; i++)
	    {
	        for(int prev = 0; prev < i; prev++)
	        {
	            if(arr[i] > arr[prev] &&(dp1[i] < 1 + dp1[prev]))
	            {
	                dp1[i] = 1 + dp1[prev];
	            }
	        }
	        maxi = max(maxi, dp1[i]);
	    }
	    
	    // Longest Descreasing Subsequence
	    maxi = 0;
	    for(int i = n-1; i >= 0; i--)
	    {
	        for(int prev = n-1; prev > i; prev--)
	        {
	            if(arr[i] > arr[prev] &&(dp2[i] < 1 + dp2[prev]))
	            {
	                dp2[i] = 1 + dp2[prev];
	            }
	        }
	        maxi = max(maxi, dp2[i]);
	    }
	    
	    maxi = 0;
	    for(int i = 0; i < n; i++)
	    {
	        maxi = max(maxi, dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends