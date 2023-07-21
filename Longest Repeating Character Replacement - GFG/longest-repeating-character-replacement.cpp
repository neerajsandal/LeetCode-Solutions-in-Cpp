//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> map;
        
        int maxi = 0;
        
        while(j < S.size())
        {
            map[S[j]]++;
            // find the maximum occurence of element in given window
            maxi = max(maxi, map[S[j]]);
            if((j-i+1) - maxi > K)
            {
                map[S[i]]--;
                i++;
            }
            
            //length of the largest similar sliding window
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends