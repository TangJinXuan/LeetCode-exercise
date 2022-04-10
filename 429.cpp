429. N 叉树的层序遍历
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // vector<int>
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        vector<Node*> nodeList;
        vector<int>init;
        init.push_back(root->val);
        res.push_back(init);
        nodeList=root->children;
        // cout<<nodeList[0]->val;
        while(!nodeList.empty())
        {
            vector<int>tempRes;
            vector<Node*> temp;
            for(int i=0;i<nodeList.size();++i)
            {
                // cout<<nodeList[i]->val;
                tempRes.push_back(nodeList[i]->val);
                for(auto j:nodeList[i]->children)
                {
                    // cout<<"test";
                    temp.push_back(j);
                }
            }
            nodeList=temp;
            res.push_back(tempRes);
            // cout<<"test";
        }
        return res;
    }
};