//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
    int n = str.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'V' && i-1 >= 0 && str[i-1] == 'I') ans+=3;
        else if(str[i] == 'X' && i-1 >= 0 && str[i-1] == 'I') ans+=8;
        else if(str[i] == 'L' && i-1 >= 0 && str[i-1] == 'X') ans+=30;
        else if(str[i] == 'C' && i-1 >= 0 && str[i-1] == 'X') ans+=80;
        else if(str[i] == 'D' && i-1 >= 0 && str[i-1] == 'C') ans+=300;
        else if(str[i] == 'M' && i-1 >= 0 && str[i-1] == 'C') ans+=800;
        else if(str[i] == 'I') ans+= 1;
        else if(str[i] == 'V') ans+=5;
        else if(str[i] == 'X') ans+=10;
        else if(str[i] == 'L') ans+=50;
        else if(str[i] == 'C') ans+=100;
        else if(str[i] == 'D') ans+=500;
        else if(str[i] == 'M') ans+=1000;
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends