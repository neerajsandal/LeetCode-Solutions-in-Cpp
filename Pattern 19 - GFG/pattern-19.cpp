//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                if(j <= i)
                    cout << "*";
                else
                    cout << " ";
            }
            for(int j = n-1; j >= 0; j--)
            {
                if(j <= i)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j <= i)
                    cout << "*";
                else
                    cout << " ";
            }
            for(int j = n-1; j >= 0; j--)
            {
                if(j <= i)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends