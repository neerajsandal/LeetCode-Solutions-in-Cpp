//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    public:
    //Function to insert heap.
    void insertHeap(int &num)
    {
        if(maxHeap.empty() || maxHeap.top() > num)
            maxHeap.push(num);
        else
            minHeap.push(num);

        if(maxHeap.size() > minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()+1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top()+minHeap.top())/2;
        else if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else return minHeap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends