//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        int n = S.size();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int maxi = 0, ans = 0;
        
        while(j < n)
        {
            mp[S[j]]++;
            maxi = max(maxi, mp[S[j]]);
            if((j-i+1 - maxi) > K){
                mp[S[i]]--;
                i++;
            }
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