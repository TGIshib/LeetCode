class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1); 
        l2 = reverse(l2);
        int rem = 0;
        ListNode* head = new ListNode(0);
        ListNode *pr = head;
        while(l1 && l2){
            pr->next = new ListNode( (l1->val + l2->val + rem) % 10);
            rem = (l1->val + l2->val + rem) / 10;
            pr = pr->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1){
            pr->next = new ListNode( (l1->val + rem) % 10);
            rem = (l1->val + rem) / 10;
            pr = pr->next;
            l1 = l1->next; 
        }
         while(l2){
            pr->next = new ListNode( (l2->val + rem) % 10);
            rem = (l2->val + rem) / 10;
            pr = pr->next;
            l2 = l2->next;
        }
        if(rem){
            pr->next = new ListNode(1);
        }
        return reverse(head->next);
    }
    
    ListNode* reverse(ListNode* l){
        ListNode* pr = NULL, *cur = l;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pr;
            pr = cur;
            cur = tmp;
        }
        return pr;
    }
};