//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job arr1, Job arr2)
    {
        return arr1.profit > arr2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Firstly sort all the jobs on the basis of profit in decreasing order;
        sort(arr, arr+n, cmp);
        
        int maxiDead = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            maxiDead = max(arr[i].dead, maxiDead);
        }
        vector<int> temp(maxiDead+1, -1);
        
        int count = 0;
        int total = 0;
        for(int i = 0; i < n; i++)
        {
           int id = arr[i].id;
           int dead = arr[i].dead;
           int profit = arr[i].profit;
           
           for(int k = dead; k >= 1; k--)
           {
               if(temp[k] == -1)
               {
                   temp[k] = id;
                   total += profit;
                   count++;
                   break;
               }
           }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(total);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends