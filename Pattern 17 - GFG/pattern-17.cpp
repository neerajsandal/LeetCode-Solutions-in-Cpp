//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        
        for(int i = 0; i < n; i++)
        {
            int ascii = 64;
            for(int j = n-1; j >= 0; j--)
            {
                if(j <= i){
                    ascii++;
                    cout << char(ascii);
                }
                else{
                    cout << " ";
                }
            }
            for(int j = 1; j <= i; j++)
            {
                ascii--;
                cout << char(ascii);
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