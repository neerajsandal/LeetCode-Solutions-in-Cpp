//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
       stack<int> s;
       for(int i = 0; i < S.length(); i++){
           
           if(S[i] == '+'){
               int t1 = s.top();
               s.pop();
               int t2 = s.top();
               s.pop();
               s.push(t1+t2);
           }
           else if(S[i] == '-'){
               int t1 = s.top();
               s.pop();
               int t2 = s.top();
               s.pop();
               s.push(t2-t1);
           }
           else if(S[i] == '*'){
               int t1 = s.top();
               s.pop();
               int t2 = s.top();
               s.pop();
               s.push(t2*t1);
           }
           else if(S[i] == '/'){
               int t1 = s.top();
               s.pop();
               int t2 = s.top();
               s.pop();
               s.push(t2/t1);
           }
           else{
               int a = int(S[i])-48;
               s.push(a);
           }
       }
       return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends