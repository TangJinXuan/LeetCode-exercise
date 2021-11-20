1448. 统计二叉树中好节点的数目
给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
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
    int goodNodesCount(TreeNode*root, int maxNum)
    {
        int left(0),right(0),res(0);
        // cout<<root->val<<" "<<maxNum<<endl;
        if(root->val>=maxNum)
        {
            res=1;
            maxNum=root->val;
        }
        if(root->left!=nullptr)
            left=goodNodesCount(root->left,maxNum);
        if(root->right!=nullptr)
            right=goodNodesCount(root->right,maxNum);
        return res+left+right;
    }
    int goodNodes(TreeNode* root) {
        return goodNodesCount(root,root->val);
    }
};