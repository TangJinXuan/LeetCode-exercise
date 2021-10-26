230. 二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
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
    void find_k(priority_queue<int>& kmin,TreeNode*head,int k)
    {
        if(kmin.size()<k)
            kmin.push(head->val);
        else if(head->val<kmin.top())
        {
            kmin.pop();
            kmin.push(head->val);
        }
        if(head->left!=nullptr)
            find_k(kmin, head->left, k);
        if(head->right!=nullptr)
            find_k(kmin, head->right, k);    
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> kmin;
        find_k(kmin, root,k);
        return kmin.top();
    }
};