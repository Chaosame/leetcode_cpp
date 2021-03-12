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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //先把中序的节点存入unordered_map 这样可以快查出某点在中序中的位置
        //先序的第一个是头 用头把中序分成两半 左边是左子树 右边是右子树
        //从先序中找到左子树长度的一组递归调用 右子树同理
    }
};