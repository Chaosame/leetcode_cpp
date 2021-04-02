/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> nmap;
    Node* copyRandomList(Node* head) {
        //递归 
        if(!head) return nullptr;
        if(nmap.count(head)>0) return nmap[head];//哈希表中有就直接用
        //没有自己创建
        Node* new_node = new Node(head->val);
        nmap[head] = new_node ;
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
};
// @lc code=end

