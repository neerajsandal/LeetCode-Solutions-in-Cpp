//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        bool flag = true;
        stack<char> s;
        int size = x.size();
        for(int i = 0; i < size; i++)
        {
            char ch = x[i];
            if(ch == '[' || ch == '{' || ch == '(') 
                s.push(ch);
            else if(ch == ']')
            {
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(ch == '}')
            {
                if(!s.empty() && s.top() == '{'){
                    s.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(ch == ')')
            {
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(s.empty()) return flag;
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends