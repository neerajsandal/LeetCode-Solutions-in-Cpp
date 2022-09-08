/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            if(n == 1){
                return NULL;
            }
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp != NULL){
            ListNode *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
      //      delete nxt;
        }
        head = prev;
        temp = head;
        
         if(n == 1){
            head = head->next;
        }
        else{
        int count = 2;
        while(temp != NULL && count !=n){
            count++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
    //    delete temp;
        }
        temp = head;
        prev = NULL;
        while(temp != NULL){
            ListNode *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        delete temp;
 //       delete head;
        return prev;
    }
};