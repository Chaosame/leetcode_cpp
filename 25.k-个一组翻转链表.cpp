/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //递归 先对头部按组翻转 移动指针到第二组的第一个 进行递归 把返回第二组的头
        ListNode * prev = nullptr; // 目前反转的链表的头
        ListNode * cur = head;// 现在的头
        ListNode * tail = head;//现在的头会变成最后的尾 先存起来
        ListNode* tmp = head;
        int length = 0;
        while(tmp){ // 测试一下现在的链长
            tmp = tmp->next;
            length++;
            if (length>=k){
                break;
            }
        } //出来tmp为空或者length>=k
        if (length<k){
            return head;
        }
        for(int i=0;i<k;i++){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* next_group = reverseKGroup(cur,k);
        tail->next = next_group;
        return prev;
    }
};
// @lc code=end

