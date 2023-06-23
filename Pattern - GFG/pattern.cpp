//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        int flag = 1;
        for(int i = n; i >= 1; i--)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i <= j){
                    if(i == j || flag == 1){
                        cout << "*";
                        flag = 0;
                    }
                    else if(flag == 0){
                        cout << " ";
                        flag = 1;
                    }
                }
                else{
                    cout << " ";
                }
            }
            for(int j = n-1; j >= 1; j--)
            {
                if(i <= j){
                    if(i == j || flag == 1){
                        cout << "*";
                        flag = 0;
                    }
                    else if(flag == 0){
                        cout << " ";
                        flag = 1;
                    }
                }
                else{
                    cout << " ";
                }
            }
            cout << endl;
        }
        
        flag = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                 if(i <= j)
                {
                    if(i == j || flag == 1)
                    {
                        cout << "*";
                        flag = 0;
                    }
                    else if(flag == 0){
                        cout << " ";
                        flag = 1;
                    }
                }
                else{
                    cout << " ";
                }
            }
            for(int j = n-1; j >= 1; j--)
            {
                if(i <= j)
                {
                    if(i == j || flag == 1)
                    {
                        cout << "*";
                        flag = 0;
                    }
                    else if(flag == 0){
                        cout << " ";
                        flag = 1;
                    }
                }
                else{
                    cout << " ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends