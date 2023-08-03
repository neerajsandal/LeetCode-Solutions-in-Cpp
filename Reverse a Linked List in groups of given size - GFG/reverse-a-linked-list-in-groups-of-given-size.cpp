//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    void reverse1(node *start, node *end)
    {
        node *p = NULL, *c = start, *n = start->next;
        while(p != end)
        {
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
    }
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL || head->next == NULL || k == 1) return head;
        node *dummy = new node(-1); // creating a dummy node before head;
        dummy->next = head;
        
        node *start = head, *end = head, *beforehead = dummy, *temp = end;
        int i = 0;
        while(end != NULL)
        {
            i++;
            if(i % k == 0)
            {
                start = beforehead->next;
                temp = end->next;
                reverse1(start, end);
                beforehead->next = end;
                start->next = temp;
                beforehead = start;
                end = temp;
            }
            else{
                end = end->next;
            }
        }
        
        if(temp != NULL)
        {
            start = beforehead->next;
            node *prev = NULL;
            node *curr = start;
            
            while(curr != NULL)
            {
                node *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            beforehead->next = prev;
        }
        return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends