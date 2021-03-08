/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> choose,not_choose;

    void dfs(TreeNode* node){
        if(!node){
            return;//节点为空直接返回
            }
        //否则进行后序遍历 用后序遍历的原因是根的值依赖于孩子的值
        dfs(node->left);
        dfs(node->right);
        //对根处理 能选2棵子树肯定比1课子树的值要大 我们根据是否选择一个节点进行分类讨论
        choose[node] = node->val + not_choose[node->left]+not_choose[node->right]; //如果选择根 那么孩子不能选 走not_choose
        not_choose[node] = max(choose[node->left],not_choose[node->left]) + max(choose[node->right],not_choose[node->right]);  
}
  
    
    
    int rob(TreeNode* root) {
        dfs(root);
        return max(choose[root],not_choose[root]);
    }
};
// @lc code=end
