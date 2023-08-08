//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> vect;
        int val = 0;
        for(int i = 0; i < n; i++)
        {
            bool flag = true;
            for(int j = 0; j < n; j++)
            {
                if(M[i][j] != 0)
                {
                    flag = false;
                }
            }
            if(flag){
                vect.push_back(i);
            }
        }
        
        for(int j = 0; j < vect.size(); j++)
        {
            bool flag = true;
            for(int i = 0; i < n; i++)
            {
                if(M[i][vect[j]] == 0)
                {
                    if(vect[j] != i){
                        flag = false;
                    }
                }
            }
            
            if(flag) return vect[j];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends