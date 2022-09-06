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
    ListNode* reverse(ListNode* l){
        if(l == NULL || l->next == NULL){
            return l;
        }
        ListNode *temp = NULL;
        ListNode *prev = NULL;
        while(l != NULL){
            temp = l->next;
            l->next = prev;
            prev = l;
            l = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0, tempcarry = 0;
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *prev;
        while(l1 != NULL && l2 != NULL){
            int count = (l1->val)+(l2->val);
            carry = tempcarry;
            count+=carry;
            tempcarry = count/10;
            count = (count)%10;
            if(carry == 0){
                l1->val = count;
                l2->val = count;
            }
            else if(carry == 1){
                l1->val = count;
                l2->val = count;
            }
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != NULL){
            ListNode *prev1;
            while(tempcarry == 1 && l1 != NULL){   
                int count = l1->val+1;
                tempcarry = count/10;
                count%=10;
                l1->val = count;
                prev1 = l1;
                l1 = l1->next;
            }
            if(tempcarry == 1){
                ListNode *tt = new ListNode(1);
                prev1->next = tt;
            }
            head1 = reverse(head1);
            return head1;
        }
        
        if(l2 != NULL){
           ListNode *prev1;
            while(tempcarry == 1 && l2 != NULL){
                int count = l2->val+1;
                tempcarry = count/10;
                count%=10;
                l2->val = count;
                prev1 = l2;
                l2 = l2->next;
            }
         //   cout << tempcarry << " ";
            if(tempcarry == 1){
                ListNode *tt = new ListNode(1);
                prev1->next = tt;
            }
            head2 = reverse(head2);
            return head2;
        }
        if(tempcarry == 1){
            cout << tempcarry << " ";
            ListNode *ans = new ListNode(1);;
            prev->next = ans;
           // head1 = reverse(head1);
        }
        head1 = reverse(head1);
        if(head1->val >= 10){
            head1->val = head1->val%10;
            ListNode *ans = new ListNode(1);;
            ans->next = head1;
            head1 = ans;
        }
        return head1;
    }
};