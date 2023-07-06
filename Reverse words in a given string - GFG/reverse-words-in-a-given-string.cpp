//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverseString(string &S, int i, int n)
    {
        while(i < n)
        {
            swap(S[i], S[n]);
            i++;
            n--;
        }
    }
    string reverseWords(string S) 
    { 
        int n = S.size()-1;
        reverseString(S, 0, n);
        
        int j = 0;
        int i = 0;
        for(i = 0; i <= n; i++)
        {
            if(S[i] == '.'){
                reverseString(S, j, i-1);
                j = i+1;
            }
        }
        reverseString(S, j, i-1);
        return S;
    }
    // string reverseWords(string S) 
    // { 
    //     string str = "", temp = "";
    //     for(int i = S.size()-1; i >= 0; i--)
    //     {
    //         if(S[i] == '.')
    //         {
    //             reverse(temp.begin(), temp.end());
    //             str += temp + ".";
    //             temp="";
    //         }
    //         else{
    //             temp += S[i];
    //         }
    //     }
    //     reverse(temp.begin(), temp.end());
    //     str += temp;
    //     return str;
    // } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends