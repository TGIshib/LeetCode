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
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	ListNode* head;
	Solution(ListNode* head) {
		this->head = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* h = head->next;
		int rval = head->val;
		int i = 2;
		while (h) {
			int r = rand() % i;
			if (!r) rval = h->val;
			h = h->next;
			i++;
		}
		return rval;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/