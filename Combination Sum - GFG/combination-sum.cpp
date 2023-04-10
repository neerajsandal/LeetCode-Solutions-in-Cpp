//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void helper(vector<int> &nums, int target, int ind, vector<int> &temp, vector<vector<int>> &ans){
        if(ind == nums.size()){
            if(target == 0)
            {
               // sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            return;
        }
        if(nums[ind] <= target){
            temp.push_back(nums[ind]);
            helper(nums, target-nums[ind], ind, temp, ans);
            temp.pop_back();
        }
        helper(nums, target, ind+1, temp, ans);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()),A.end());
        vector<vector <int>> ans;
        vector<int> temp;
        helper(A,B,0, temp, ans);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends