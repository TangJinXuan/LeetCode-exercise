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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        if(root1!=nullptr)
            getOneTree(root1,tree1);
        if(root2!=nullptr)
            getOneTree(root2,tree2);
        //tree1.insert(tree1.end(),tree2.begin(),tree2.end());
        // sort(tree1.begin(),tree1.end());
        int index1(0),index2(0);
        vector<int>res;
        // auto p1 = tree1.begin(), p2 = tree2.begin();
        // while (true) {
        //     if (p1 == tree1.end()) {
        //         res.insert(res.end(), p2, tree2.end());
        //         break;
        //     }
        //     if (p2 == tree2.end()) {
        //         res.insert(res.end(), p1, tree1.end());
        //         break;
        //     }
        //     if (*p1 < *p2) {
        //         res.push_back(*p1++);
        //     } else {
        //         res.push_back(*p2++);
        //     }
        // }

        while(index1<tree1.size()&&index2<tree2.size())
        {
            if(tree1[index1]<tree2[index2])
            {
                res.push_back(tree1[index1]);
                ++index1;
            }
            else
            {
                res.push_back(tree2[index2]);
                ++index2;
            }
        }
        // cout<<index1<<" "<<index2<<" "<<tree1.size();
        if(index1<tree1.size())
            while(index1<tree1.size())
            {
                res.push_back(tree1[index1]);
                // cout<<index2;
                ++index1;
            }
        else
            while(index2<tree2.size())
            {
                res.push_back(tree2[index2]);
                ++index2;
            }
        return res;
    }
    void getOneTree(TreeNode* root,vector<int>&res){
        if(root->left!=nullptr)
        {
            getOneTree(root->left,res);
        }
        res.push_back(root->val);
        if(root->right!=nullptr)
        {
            getOneTree(root->right,res);
        }
        // return res;
    }
};