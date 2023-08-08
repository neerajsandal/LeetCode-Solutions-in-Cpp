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
        // 1. push all the indexes into the stack
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            st.push(i);
        }
        
        while(st.size() > 1)
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            
            if(M[a][b] == 1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        if(st.empty()) return -1;
        
        // row check
        bool rowcheck = true;
        bool colcheck = true;
        for(int i = 0; i < n; i++)
        {
            if(M[st.top()][i] != 0)
            {
                rowcheck = false;
            }
        }
        
        // colcheck
        for(int i = 0; i < n; i++)
        {
            if(M[i][st.top()] != 1 && st.top() != i)
            {
                colcheck = false;
            }
        }

        if (rowcheck && colcheck) return st.top();
        else return -1;
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