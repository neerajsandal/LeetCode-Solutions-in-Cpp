//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    bool binarySearch(vector<int> arr, int x)
    {
        int low = 0;
        int high = arr.size()-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] < x)
                low = mid+1;
            else if(arr[mid] > x)
                high = mid-1;
            else 
                return true;
        }
        return false;
    }
    bool search(vector<vector<int>> matrix, int n, int m, int x) 
    {
        for(int i = 0; i < n; i++)
        {
            if(binarySearch(matrix[i], x)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends