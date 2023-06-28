//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int, vector<int>, greater<int>> pq;
	    int i = 0;
	    vector<int> vect;
	    for(; i < k; i++){
	        pq.push(arr[i]);
	        vect.push_back(0);
	    }
	    
	    for(; i < n; i++){
	        if(pq.top() < arr[i])
	        {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    
	    int size = pq.size();
	    for(int i = size-1; i >= 0; i--)
	    {
	        vect[i] = pq.top();
	        pq.pop();
	    }
	    return vect;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends