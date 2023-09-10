//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool compare(string &s1, string &s2)
    {
        int i = 0, j = 0;
        int n = s1.size();
        int m = s2.size();
        
        if(n - m != 1) return false;
        while(i < n)
        {
            if(j < m && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        if(i == n && j == m) return true;
        else return false;
    }
    
    bool static comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
    
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int maxi = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++)
            {
                if(compare(words[i], words[prev]))
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends