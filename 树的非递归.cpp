/**
    * 后序遍历 非递归
    * 双栈法
    * @param root
    */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //迭代 用根右左的顺序遍历 在访问时加入另一个栈中 最后把另一个栈反向输出即可
        vector<int> ans;
        TreeNode* cur=root;
        stack<TreeNode*>st;
        stack<TreeNode*>output;
        while(cur||!st.empty()){
            if(cur){
                st.push(cur);
                output.push(cur);
                cur=cur->right;
            }
            else{
            cur = st.top();
            st.pop();
            cur =cur->left;
}

        }
        while(!output.empty()){
            ans.push_back(output.top()->val);
            output.pop();
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root){};
};

//先序 中序
   void PreOrder(BiTree T){
    InitStack(S);
    BiTree p=T;
    while(p || !StackEmpty(S)){
        if(p){
            visit(p);
            push(S,p);
            p=p->lchild;
        }
        else{
            pop(S,p);
            p=p->rchild;
        }
    }

    
}
