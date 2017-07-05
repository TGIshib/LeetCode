/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;
		ListNode* pr, *cur, *next;
		pr = NULL; cur = head;
		while (cur != NULL) {
			next = cur->next;
			cur->next = pr;
			pr = cur;
			cur = next;
		}
		return pr;

	}
};