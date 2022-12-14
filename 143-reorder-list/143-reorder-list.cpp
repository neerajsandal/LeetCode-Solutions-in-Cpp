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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        vector<int> v;
        ListNode *temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        for(int i = 0; i < v.size()/2; i++){
            temp->val = v[i];
            temp = temp->next;
            temp->val = v[v.size()-1-i];
            temp = temp->next;
        }
        if(v.size()%2 !=0){
            temp->val = v[v.size()/2];
        }
    }
};