//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        for(int i = 0; i < n; i++)
        {
            int flag = (i+1)%2;
            for(int j = 0; j <= i; j++)
            {
                if(flag){
                    cout << flag << " ";
                    flag--;
                }
                else{
                    cout << flag << " ";
                    flag++;
                }
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