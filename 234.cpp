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
	bool isPalindrome(ListNode* head) {
		ListNode* fast = head, *slow = head;
		ListNode* pr = NULL;
		while (fast) {
			if (fast->next == NULL) {
				fast = slow->next;
				slow = pr;
				break;
			}
			if (fast->next->next == NULL) {
				ListNode* tmp = slow->next;
				slow->next = pr;
				pr = slow;
				slow = tmp;

				fast = slow;
				slow = pr;
				break;
			}
			fast = fast->next->next;
			ListNode* tmp = slow->next;
			slow->next = pr;
			pr = slow;
			slow = tmp;
		}
		while (fast) {
			if (fast->val != slow->val) return false;
			fast = fast->next;
			slow = slow->next;
		}
		return true;
	}
};