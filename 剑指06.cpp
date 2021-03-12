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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        while(head){
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty()){
            int v = s.top();
            s.pop();
            ans.push_back(v);
        }
        return ans;
    }
};