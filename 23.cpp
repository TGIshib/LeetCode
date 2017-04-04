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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int, ListNode*> > q;
        for(ListNode* l : lists){
            if(l) q.push(make_pair(-l->val, l));
        }
        if(q.empty()) return NULL;
        ListNode * head = q.top().second;
        q.pop();
        if(head->next != NULL) q.push(make_pair(-head->next->val,head->next));
        ListNode * res = head;
        while(!q.empty()){
            auto cur = q.top(); q.pop();
            head->next = cur.second;
            if(cur.second->next != NULL) q.push(make_pair(-cur.second->next->val,cur.second->next));
            head = head->next;
        }
        return ret;
    }
};