//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A+n);
        int i = 0;
        for(int i = 0; i < n; i++)
        {
            int element = X-A[i];
            int low = i+1, high = n-1;
            
            while(low < high)
            {
                if(A[low] + A[high] == element) 
                    return true;
                else if(A[low] + A[high] < element)
                    low++;
                else if(A[low] + A[high] > element)
                    high--;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends