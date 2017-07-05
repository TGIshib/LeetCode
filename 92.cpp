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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || m == n) return head;
		ListNode* ns = new ListNode(-1);
		ns->next = head;
		ListNode* goodDaySir = ns;
		m--; n++;
		while (m) {
			goodDaySir = goodDaySir->next;
			m--;
		}
		ListNode * inServiseToRome = ns;
		while (n) {
			inServiseToRome = inServiseToRome->next;
			n--;
		}
		//
		ListNode* pr, *cur, *nxt;
		ListNode *tmp = goodDaySir->next;
		pr = NULL; cur = tmp;
		while (cur != inServiseToRome) {
			nxt = cur->next;
			cur->next = pr;
			pr = cur;
			cur = nxt;
		}
		goodDaySir->next = pr;
		tmp->next = inServiseToRome;
		return ns->next;
		//
	}
};