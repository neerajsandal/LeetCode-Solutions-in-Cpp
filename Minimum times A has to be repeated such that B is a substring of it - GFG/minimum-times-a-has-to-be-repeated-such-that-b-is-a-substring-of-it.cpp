//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool checkSubstring(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int j = 0;
        
        for(int i = 0; i <= n-m; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(a[i+j] != b[j])
                {
                    break;
                }
            }
            if(j == m) return true;
        }
        return false;
    }
    int minRepeats(string A, string B) {
        
        if(A.size() > B.size()) return -1;
        string ans = A;
        int count = 1;
        while(ans.size() < B.size())
        {
            ans += A;
            count++;
        }
        if(checkSubstring(ans, B)) return count;
        if(checkSubstring(ans+A, B)) return count+1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends