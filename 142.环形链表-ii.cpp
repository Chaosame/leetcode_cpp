/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        if(!head->next) return nullptr;
        ListNode* s = head->next;
        ListNode* f =head->next->next;
        //第一次相遇
        while(f&&f!=s&&f->next){
            s = s->next;
            f = f->next->next;
        }
        if(!f||!f->next) return nullptr; //到了末尾了
        //此时f比s多走bn 再走a就回到链表环的入口
        f = head;
        while(f!=s){
            f = f->next;
            s= s->next;
        }
        return s;
    }
};
// @lc code=end

