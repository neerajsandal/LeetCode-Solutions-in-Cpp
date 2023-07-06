//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b)
    {
        return a.second < b.second;
    }
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
        vector<pair<pair<int,int>, int>> vect;
        for(int i = 0; i < n; i++)
        {
            vect.push_back({{i+1, start[i]}, end[i]});
        }
        
        sort(vect.begin(), vect.end(), cmp);
        
        
        vector<int> ans;
        ans.push_back(vect[0].first.first);
        int end_time = vect[0].second;
        
        for(int i = 0; i < n; i++)
        {
            if(end_time < vect[i].first.second)
            {
                ans.push_back(vect[i].first.first);
                end_time = vect[i].second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends