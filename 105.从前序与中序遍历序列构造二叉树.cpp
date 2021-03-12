/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

/** 本题的优化做法是先把中序遍历中的所有数存入一个hashmap,然后就可以在O(1)中找到
 * 
 */
class Solution {
public:
unordered_map<int,int> m;
TreeNode* rebuild(vector<int> pre,vector<int> vin,int pl,int pr,int vl,int vr){
//         cout<<pl<<pr<<vl<<vr<<endl;
        //左闭右闭
        if(pl>pr){
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pl]); //先序的最左是根
        if (pl==pr){
            return root;
        }
        // vector<int>::iterator it = find(vin.begin(),vin.end(),pre[pl]);
        int tar = m[pre[pl]]; //在中序中的下标位置
//         cout<<tar<<endl;
        int l_len = tar-vl;//中序中的左边长度
        int r_len = vr-tar;//中序的右边长度
//         cout<<l_len<<r_len<<endl;
        root->left = rebuild(pre, vin, pl+1, pl+l_len, tar-l_len,tar-1);
        root->right = rebuild(pre,vin,pl+l_len+1,pl+l_len+r_len,tar+1,tar+r_len);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        return rebuild(preorder,inorder,0,n-1,0,n-1);
    }
};
// @lc code=end

