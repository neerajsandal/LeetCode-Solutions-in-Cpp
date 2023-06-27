//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // i = 0 to 2n-2
        // j = 0 to 2n-2
        for(int i = 0; i < 2*n-1; i++)
        {
            for(int j = 0; j < 2*n-1; j++)
            {
                int top = i;
                int left = j;
                int right = (2*n-2)-j;
                int bottom = (2*n-2)-i;
                int value = n - min(min(left,right), min(top, bottom));
                cout << value << " ";
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