/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next){
            return head; // 只有头或者没有头不用反转了
        }
        ListNode* cur = head;
        ListNode* pre = nullptr; // 已经反转的链表的头
        while(cur){ //当前节点不空都需要反转
            ListNode* next = cur->next; // 存好下一个节点
            cur->next = pre; // 把现在反转的链表放在它后面
            pre = cur;
            cur = next;
        }
        return pre; // 返回虚构头的next
    }
};
// @lc code=end

