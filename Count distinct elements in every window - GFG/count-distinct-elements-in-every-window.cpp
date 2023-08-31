//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i = 0; i < k; i++)
        {
            map[A[i]]++;
        }
        
        ans.push_back(map.size());
        
        for(int i = k; i < n; i++)
        {
            if(map[A[i-k]] == 1){
                map.erase(A[i-k]);
            }
            else{
                map[A[i-k]]--;
            }
            
            map[A[i]]++;
            ans.push_back(map.size());
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends