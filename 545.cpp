545. 二叉树的边界
二叉树的 边界 是由 根节点 、左边界 、按从左到右顺序的 叶节点 和 逆序的右边界 ，按顺序依次连接组成。

左边界 是满足下述定义的节点集合：

根节点的左子节点在左边界中。如果根节点不含左子节点，那么左边界就为 空 。
如果一个节点在左边界中，并且该节点有左子节点，那么它的左子节点也在左边界中。
如果一个节点在左边界中，并且该节点 不含 左子节点，那么它的右子节点就在左边界中。
最左侧的叶节点 不在 左边界中。
右边界 定义方式与 左边界 相同，只是将左替换成右。即，右边界是根节点右子树的右侧部分；叶节点 不是 右边界的组成部分；如果根节点不含右子节点，那么右边界为 空 。

叶节点 是没有任何子节点的节点。对于此问题，根节点 不是 叶节点。

给你一棵二叉树的根节点 root ，按顺序返回组成二叉树 边界 的这些值。

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
    vector<int> leftBound(TreeNode* root)
    {
        vector<int> res;
        if(root==nullptr)
            return res;
        // cout<<root->val<<" ";
        if(root->left==nullptr)
        {
            if(root->right!=nullptr)
            {
                // cout<<"right"<<endl;
                res.push_back(root->val);
                vector<int> res1=leftBound(root->right);
                res.insert(res.end(),res1.begin(),res1.end());
            }
        }
        else
        {
            // cout<<root->val<<" ";
            res.push_back(root->val);
            // cout<<"left"<<endl;
            vector<int> res1=leftBound(root->left);
            res.insert(res.end(),res1.begin(),res1.end());
        }
        return res;
    }
    vector<int> leaf(TreeNode* root)
    {
        vector<int> res;
        if(root==nullptr)
            return res;
        if(root->left!=nullptr)
        {
            vector<int> res1=leaf(root->left);
            res.insert(res.end(),res1.begin(),res1.end());
        }
        if(root->right!=nullptr)
        {
            vector<int> res1=leaf(root->right);
            res.insert(res.end(),res1.begin(),res1.end());
        }
        if(root->left==nullptr&&root->right==nullptr)
        {
            res.push_back(root->val);
            // cout<<root->val<<endl;
        }
        return res;
    }
    vector<int> rightBound(TreeNode* root)
    {
        vector<int> res;
        if(root->right==nullptr)
        {
            if(root->left!=nullptr)
            {
                res=rightBound(root->left);
                res.push_back(root->val);
            }
        }
        else
        {
            res=rightBound(root->right);
            res.push_back(root->val);
        }
        return res;
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        res.push_back(root->val);
        if(root->left)
        {
            vector<int> leftRes=leftBound(root->left);
            res.insert(res.end(),leftRes.begin(),leftRes.end());
        }
        if(root->left||root->right)
        {
            vector<int> res1=leaf(root);
            res.insert(res.end(),res1.begin(),res1.end());
        }
        if(root->right)
        {
            vector<int> rightRes=rightBound(root->right);
            res.insert(res.end(),rightRes.begin(),rightRes.end());
        }
        return res;
    }
};