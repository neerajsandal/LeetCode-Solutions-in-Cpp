//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    class Node{
        public:
        int data, row, col;
        Node(int data, int row, int col)
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    class compare{
        public:
        bool operator()(Node *a, Node *b){
            return a->data > b->data;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<Node*, vector<Node*>, compare> pq;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            Node *temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            
            int data = temp->data;
            int row = temp->row;
            int col = temp->col;
            
            if(col+1 < arr[row].size()){
                Node *t = new Node(arr[row][col+1], row, col+1);
                pq.push(t);
            }
            ans.push_back(data);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends