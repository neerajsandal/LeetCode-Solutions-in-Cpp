//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1, temp =0;
        int i = 0, j = 0;
        unordered_map<char, int> map;
        while(j < s.size())
        {
            map[s[j]]++;
            if(map.size() == k)
            {
                ans = max(ans, j-i+1);
            }
            
            while(map.size() > k)
            {
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
            }
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends