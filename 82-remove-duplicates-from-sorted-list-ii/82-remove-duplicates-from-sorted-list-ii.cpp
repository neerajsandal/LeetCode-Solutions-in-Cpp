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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        unordered_map<int, int> map;
        ListNode *temp = head;
        while(temp!=NULL){
            map[temp->val]++;
            temp = temp->next;
        }
        
        temp = head;
        ListNode *prev = NULL;
        while(temp!=NULL){
            
            if(map[temp->val] == 1){
                if(prev == NULL){
                    prev = temp;
                    head = temp;
                }
                else{
                    prev->next = temp;
                    prev = temp;
                }
            }
            temp = temp->next;
        }
        
        delete temp;
        if(prev == NULL){
            delete head;
            return prev;
        }
        prev->next = NULL;
        return head;
    }
};
