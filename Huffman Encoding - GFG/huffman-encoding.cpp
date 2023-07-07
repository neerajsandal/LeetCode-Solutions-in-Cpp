//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int data; 
    Node *left;
    Node *right;
    
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void traverse(Node* root, vector<string> &ans, string temp)
{
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        temp = "";
        return;
    }
    traverse(root->left, ans, temp+"0");
    traverse(root->right, ans, temp+"1");
}
class compare{
    public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, compare> pq;
		    for(int i = 0; i < N; i++)
		    {
		        Node *temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1)
		    {
		        Node *left = pq.top();
		        pq.pop();
		        
		        Node *right = pq.top();
		        pq.pop();
		        
		        Node *root = new Node(left->data + right->data);
		        root->left = left;
		        root->right = right;
		        
		        pq.push(root);
		    }
		    
		    Node *root = pq.top();
		    pq.pop();
		    
		    string temp = "";
		    vector<string> ans;
		    traverse(root, ans, temp);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends