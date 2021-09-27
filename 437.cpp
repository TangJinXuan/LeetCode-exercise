// 437. 路径总和 III
// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
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
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return 0;
        queue<TreeNode*> routeStack;
        queue<vector<long long>> routeLength;
        routeStack.push(root);
        vector<long long> init;
        // init.push_back(0);
        routeLength.push(init);
        int res(0);
        while(!routeStack.empty())
        {
            vector<long long> tempSum=routeLength.front();
            routeLength.pop();
            TreeNode* tempNode=routeStack.front();
            routeStack.pop();
            vector<long long> newSum;
            for(auto i:tempSum)
            {
                // cout<<i<<" ";
                i=i+tempNode->val;
                // cout<<i<<endl;
                newSum.push_back(i);
                if(i==targetSum)
                    res++;
            }
            newSum.push_back(tempNode->val);
            if(tempNode->val==targetSum)
                res++;
            // for(auto i:tempSum)
            //     cout<<i<<" ";
            // cout<<endl;
            if(tempNode->left!=nullptr)
            {
                routeStack.push(tempNode->left);
                routeLength.push(newSum);
            }
            if(tempNode->right!=nullptr)
            {
                routeStack.push(tempNode->right);
                routeLength.push(newSum);
            }
        }
        return res;
    }
};