/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        //借助队列实现 用两个队列实现 来区别层次 用完一个队列直接用下层队列覆盖掉
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root); //先放入根
        while(que.size()>0){
            vector<int> cur; //此层序列
            queue<TreeNode*> next_que; //下层队列
            while(que.size()>0){
                TreeNode* top = que.front();
                if (top->left){
                next_que.push(top->left);
                }
                if(top->right){
                next_que.push(top->right);
                }
                cur.push_back(top->val);
                que.pop();
            }//出来当前队列为空 用下层队列覆盖 把此层序列加入结果
            que = next_que;
            res.push_back(cur);
        }
        return res;
    }
};
// @lc code=end

