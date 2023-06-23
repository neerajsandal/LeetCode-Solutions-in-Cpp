//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        for(int i = n; i >= 1; i--)
        {
            for(int j = n; j >= 1; j--)
            {
                if(i >= j)
                    cout << i << " ";
                else
                    cout << j << " ";
            }
            
            for(int j = 2; j <= n; j++)
            {
                if(i >= j)
                    cout << i << " ";
                else
                    cout << j << " ";
            }
            cout << endl;
        }
        
        for(int i = 2; i <= n; i++)
        {
            for(int j = n; j >= 1; j--)
            {
                if(i <= j)
                    cout << j << " ";
                else
                    cout << i << " ";
            }
            
            for(int j = 2; j <= n; j++)
            {
                if(i <= j)
                    cout << j << " ";
                else
                    cout << i << " ";
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends