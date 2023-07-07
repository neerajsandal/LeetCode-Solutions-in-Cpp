//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int, int>> vect;
    	
    	for(int i = 0; i < n; i++)
    	{
    	    vect.push_back({arr[i], dep[i]});
    	}
    	
    	sort(vect.begin(), vect.end(), cmp);
    	
    	vector<pair<int, int>> platforms;
    	platforms.push_back(vect[0]);
    	for(int i = 1; i < n; i++)
    	{
    	    bool assigned = false;
    	    for(int j = 0; j < platforms.size(); j++)
    	    {
    	        if(platforms[j].second < vect[i].first)
    	        {
    	            platforms[j] = vect[i];
    	            assigned = true;
    	            break;
    	        }
    	    }
    	    
    	    if(!assigned){
    	        platforms.push_back(vect[i]);
    	    }
    	}
    	return platforms.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends